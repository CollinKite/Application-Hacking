#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>


int main()
{
	//Handle to a window
	HWND hWnd = FindWindow(nullptr, "AssaultCube");
	std::cout << "Window Handle is: " << hWnd << std::endl;
	
	//Initial Process ID var, will fill when we get the id
	DWORD pID = NULL; //DWORD is just a unsigned long int

	//Get Process ID from the Window Handle
	GetWindowThreadProcessId(hWnd, &pID);

	std::cout << "Process ID is: " << pID << std::endl;

	//Open Handle to Process by pID, with all access. (false to not inherit)
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, false, pID);



	//ReadProcessMemory(pHandle, (LPVOID)ammo_address, &ammo, sizeof(ammo), 0);
	//ReadProcessMemory(pHandle, (LPVOID)ammoReserve_address, &ammoReserve, sizeof(ammo), 0);

	//std::cout << "Current Ammo: " << ammo << std::endl;
	//std::cout << "Current Ammo Reserve: " << ammoReserve << std::endl;
	std::cout << "Time for Unlimited Ammo :)" << std::endl;
	
	bool quit = false;
	const int maxAmm = 69;
	const int maxAmmR = 420;

	while (!quit)
	{
		//WriteProcessMemory(pHandle, (LPVOID)ammo_address, &maxAmm, sizeof(int), 0); //Update Ammo to 69
		//WriteProcessMemory(pHandle, (LPVOID)ammoReserve_address, &maxAmmR, sizeof(int), 0); //Update Ammo Reserve to 420
		if (GetKeyState(VK_ESCAPE))
		{
			quit = true;
		}
	}

	std::cout << "Cheat Exited" << std::endl;

	


	return 0;
}

