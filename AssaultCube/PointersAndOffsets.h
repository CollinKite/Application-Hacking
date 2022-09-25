#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace ac
{
	class localEntity
	{
	public:
		localEntity() = default;
		~localEntity() = default;
		const DWORD entity_ptr = 0x10F4F4;
		const DWORD entity = NULL; //Todo: Setup Dereferencing the entity ptr and assign it to this entity var
		const DWORD name =  entity + 0x225;
		const DWORD health = entity + 0xF8;
		const DWORD ammo_c = entity + 0x150; //Ammo in clip
		const DWORD ammo_r = entity + 0x128; //Ammo in reserve
	};
	

}