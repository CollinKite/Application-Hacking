#include "PointersAndOffsets.h"
#include "Memory.h"
#include <iostream>
#include <iomanip> //Used For Converting int to hex
int main()
{
	Memory mem("AssaultCube");

	std::cout << "Process Id: " << mem.pID << std::endl;
	
	std::cout << "Handle to Process: 0x" << mem.pHandle << std::endl;
	
	std::cout << "Base Address of Module: 0x" << std::hex << mem.GetModuleAddress("ac_client.exe") << std::endl;

	DWORD localPlayer = mem.readMemory<DWORD>(mem.GetModuleAddress("ac_client.exe") + LOCAL_ENTITY);

	std::cout << "Local Player: 0x" << std::hex << localPlayer << std::endl;

	std::cout << "\nPress Enter to Continue";
	std::cin.ignore();

	Player player(localPlayer);

	std::cout

	bool quit = false;

	while (!quit)
	{
		if (GetKeyState(VK_ESCAPE))
			{
				quit = true;
			}
	}

	






	
	////Handle to a window
	//HWND hWnd = FindWindow(nullptr, "AssaultCube");
	//std::cout << "Window Handle is: " << hWnd << std::endl;
	//
	////Initial Process ID var, will fill when we get the id
	//DWORD pID = NULL; //DWORD is just a unsigned long int

	////Get Process ID from the Window Handle
	//GetWindowThreadProcessId(hWnd, &pID);

	//std::cout << "Process ID is: " << pID << std::endl;

	////Open Handle to Process by pID, with all access. (false to not inherit)
	//HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, false, pID);

	//ac::localEntity* localPlayer = new ac::localEntity();


	////ReadProcessMemory(pHandle, (LPVOID)localPlayer->entity_ptr, (LPVOID)localPlayer->entity, sizeof(DWORD), 0);
	////ReadProcessMemory(pHandle, (LPVOID)ammoReserve_address, &ammoReserve, sizeof(ammo), 0);
	////std::cout << "local entity address -> " << localPlayer->entity << std::endl;
	////std::cout << "Current Ammo: " << ammo << std::endl;
	////std::cout << "Current Ammo Reserve: " << ammoReserve << std::endl;
	//std::cout << "Time for Unlimited Ammo :)" << std::endl;
	//
	//bool quit = false;
	//const int maxAmm = 69;
	//const int maxAmmR = 420;

	//while (!quit)
	//{
	//	//WriteProcessMemory(pHandle, (LPVOID)ammo_address, &maxAmm, sizeof(int), 0); //Update Ammo to 69
	//	//WriteProcessMemory(pHandle, (LPVOID)ammoReserve_address, &maxAmmR, sizeof(int), 0); //Update Ammo Reserve to 420
	//	if (GetKeyState(VK_ESCAPE))
	//	{
	//		quit = true;
	//	}
	//}

	//std::cout << "Cheat Exited" << std::endl;

	


	return 0;
}

