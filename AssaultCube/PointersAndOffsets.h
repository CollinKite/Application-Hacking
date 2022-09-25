#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <string>

namespace ac
{
	static class localEntity
	{
	public:
		const std::string Name;
		const DWORD health;
		const DWORD ammo_c; //Ammo in clip
		const DWORD ammo_r; //Ammo in reserve

	};
	

}