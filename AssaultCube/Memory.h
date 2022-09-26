#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <TlHelp32.h>
#include <string>

class Memory
{
public:
	//Constructor that Finds Process id and opens handle 
	Memory(const std::string& processName)
	{
		//Open Handle to Window, with the process name
		HWND hWnd = FindWindow(nullptr, processName.c_str());

		//Get Process ID from the Window Handle
		GetWindowThreadProcessId(hWnd, &pID);

		//Open Handle to Process with full access by pID
		pHandle = OpenProcess(PROCESS_ALL_ACCESS, false, pID);


	}

	~Memory()
	{
		if (pHandle) ::CloseHandle(pHandle);	
	}

	// Returns the base address of a module by name - Credit: https://github.com/cazzwastaken/external-aimbot/blob/main/memory.h
	const std::uintptr_t GetModuleAddress(const std::string_view moduleName) const noexcept
	{
		::MODULEENTRY32 entry = { };
		entry.dwSize = sizeof(::MODULEENTRY32);

		const auto snapShot = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);

		std::uintptr_t result = 0;

		while (::Module32Next(snapShot, &entry))
		{
			if (!moduleName.compare(entry.szModule))
			{
				result = reinterpret_cast<std::uintptr_t>(entry.modBaseAddr);
				break;
			}
		}

		if (snapShot)
			::CloseHandle(snapShot);

		return result;
	}
	
	//Reads memory from a given address
	template<typename T>
	T readMemory(DWORD address)
	{
		T buffer;
		ReadProcessMemory(pHandle, (LPVOID)address, &buffer, sizeof(T), 0);
		return buffer;
	}

	//Writes memory to a given address
	template<typename T>
	void writeMemory(DWORD address, T value)
	{
		WriteProcessMemory(pHandle, (LPVOID)address, &value, sizeof(T), 0);
	}

public:
	DWORD pID = 0;
	void* pHandle = nullptr;

};