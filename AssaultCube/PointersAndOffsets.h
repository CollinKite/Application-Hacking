#pragma once
#define WIN32_LEAN_AND_MEAN
#define LOCAL_ENTITY 0x10F4F4
#include <Windows.h>

class Player
{
public:
	Player(DWORD &add)
	{
		entity = add;
	}
	~Player() = default;
	DWORD entity = NULL; //Todo: Setup Dereferencing the entity ptr and assign it to this entity var
	const DWORD name = entity + 0x225;
	const DWORD health = entity + 0xF8;
	//const DWORD team = entity + 0x;
	
	const DWORD ammo = NULL; //equipped Weapon Ammo

	//4 Bytes away from eachother
	const DWORD X = entity + 0x4;
	const DWORD Y = entity + 0x8;
	const DWORD Z = entity + 0xC;
};