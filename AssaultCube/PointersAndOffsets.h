#pragma once
#define WIN32_LEAN_AND_MEAN
#define LOCAL_ENTITY 0x10F4F4
#include <Windows.h> //Fwd declare DWORD instead?

class Player
{
public:
	Player(DWORD &add)
	{
		entity = add;
		X += add;
		Y += add;
		Z += add;
		name += add;
		health += add;
		ammo += add;
		//team += add;
	}
	~Player() = default;

	DWORD entity = NULL;

	//4 Bytes away from eachother
	DWORD X = 0x4;
	DWORD Y = 0x8;
	DWORD Z = 0xC;

	DWORD name = 0x225;
	DWORD health = 0xF8;
	DWORD ammo = 0x150; //equipped Weapon Ammo
	//const DWORD team = entity + 0x;

};