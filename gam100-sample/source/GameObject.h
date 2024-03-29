/*
@copyright	All content � 2021 DigiPen Institute of Technology Singapore, all rights reserved.
@file		GameObject.h
@author		Ow Hong Yu (ow.h)
@course		CSD1400 Software Engineering Project 1
@Team		BananaBoi
@brief		Struct for gameobject to contain all the essential information of a game object
*//*________________________________________________________________________________________*/


#pragma once

#include "../CProcessing/inc/cprocessing.h"

/// <summary>
/// enum type of game object
/// </summary>
typedef enum OBJECT_TYPE
{
	EMPTY = 0,
	CIRCLE,
	RECTANGLE,
	WATER,
	FLOOR,
	FLOOR_MIDDLE,
	WALL,
	THREE_CORNER,
	CORNER,
	PLAYER,
	LINE,
	PLAYER_SPAWN,
	OBJECT_START,
	ENEMY_SPAWN,
	CORAL,
	GRASS,
	EXIT,
	BOAT,
	BOAT_PARTS,
	TYPE_END // LAST 

}OBJECT_TYPE;

/// <summary>
/// enum direction of game object
/// </summary>
typedef enum OBJECT_DIRECTION
{
	// rotation counterclockwise from X-axis
	UP = 0,
	LEFT,
	DOWN,
	RIGHT,
	DIRECTION_END // LAST
} OBJECT_DIRECTION;

/*!
@brief struct GameObject that contains transformation and render information
	Every objects have positional values, therefore many subclasses has a reference
	to this struct.
Special scenarios: -
*/
typedef struct
{
	CP_Vector position;
	CP_Vector scale;
	float rotation;
	int isEnabled; //think as unity go's isenabled bool
	char* tag;//think as unity go's name

	//think as unity go's tag
	enum OBJECT_TYPE type;
	enum OBJECT_DIRECTION oDirection;

} GameObject;
