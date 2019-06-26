#if defined _mainclass_included
	#endinput
#endif
#define _mainclass_included

//INVALID CLASS
/**
 * -DESCRIPTION:
 * 		-Defines an invalid class ID.
 */
#define INVALID_CLASS_ID					-1

//CLASS AMOUNT LIMIT
/**
 * -DESCRIPTION:
 * 		-Defines the class amount limit.
 */
#define MAX_CLASSES							320

//PLAYER CLASS
/**
 * -DESCRIPTION:
 * 		-Store the player class the player selects.
 */
static MainClass_PlayerClass[MAX_PLAYERS] = {INVALID_CLASS_ID, ...};

//SPAWN WORLDS
/**
 * -DESCRIPTION:
 * 		-Makes sure that the player respawns in the world belonging to the class.
 * -NOTES:
 * 		-Otherwise, when a player dies in a certain world, he will respawn in that world and not in the world belonging to the class.
 * 		-Defaults to VIRTUAL_WORLD_NORMAL.
 */
static MainClass_SpawnWorld[MAX_CLASSES] = {INVALID_VIRTUAL_WORLD_ID, ...};

//SPAWN INTERIORS
/**
 * -DESCRIPTION:
 * 		-Makes sure that the player respawns in the interior belonging to the class.
 * -NOTES:
 * 		-Otherwise, when a player dies in a certain interior, he will respawn in that interior and not in the interior belonging to the class.
 * 		-Defaults to INTERIOR_NORMAL.
 */
static MainClass_SpawnInterior[MAX_CLASSES] = {INVALID_INTERIOR_ID, ...};

//========================================INTERNAL FUNCTIONS========================================
static MainClass_InitScript() {
	for(new playerid = 0; playerid < MAX_PLAYERS; playerid++) { //Using MAX_PLAYERS instead of GetPlayerPoolSize because we need to initialize the variables of all possible player IDs
		//PLAYER CLASS
		MainClass_PlayerClass[playerid] = INVALID_CLASS_ID;
	}

	for(new classid = 0; classid < MAX_CLASSES; classid++) {
		//SPAWN WORLDS
		MainClass_SpawnWorld[classid] = INVALID_VIRTUAL_WORLD_ID;

		//SPAWN INTERIORS
		MainClass_SpawnInterior[classid] = INVALID_INTERIOR_ID;
	}
}

static MainClass_ExitScript() {
	for(new playerid = 0; playerid < MAX_PLAYERS; playerid++) { //Using MAX_PLAYERS instead of GetPlayerPoolSize because we need to reset the variables of all possible player IDs
		//PLAYER CLASS
		MainClass_PlayerClass[playerid] = INVALID_CLASS_ID;
	}

	for(new classid = 0; classid < MAX_CLASSES; classid++) {
		//SPAWN WORLDS
		MainClass_SpawnWorld[classid] = INVALID_VIRTUAL_WORLD_ID;

		//SPAWN INTERIORS
		MainClass_SpawnInterior[classid] = INVALID_INTERIOR_ID;
	}
}

//========================================HOOKED CALLBACKS========================================
#if defined FILTERSCRIPT
	public OnFilterScriptInit()
	{
		MainClass_InitScript();

		new ret = 1;
		#if defined MainClass_OnFilterScriptInit
			ret = MainClass_OnFilterScriptInit();
		#endif
		return ret;
	}
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit MainClass_OnFilterScriptInit
	#if defined MainClass_OnFilterScriptInit
		forward MainClass_OnFilterScriptInit();
	#endif

	public OnFilterScriptExit()
	{
		MainClass_ExitScript();

		new ret = 1;
		#if defined MainClass_OnFilterScriptExit
			ret = MainClass_OnFilterScriptExit();
		#endif
		return ret;
	}
	#if defined _ALS_OnFilterScriptExit
		#undef OnFilterScriptExit
	#else
		#define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit MainClass_OnFilterScriptExit
	#if defined MainClass_OnFilterScriptExit
		forward MainClass_OnFilterScriptExit();
	#endif
#else
	public OnGameModeInit()
	{
		MainClass_InitScript();

		new ret = 1;
		#if defined MainClass_OnGameModeInit
			ret = MainClass_OnGameModeInit();
		#endif
		return ret;
	}
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit MainClass_OnGameModeInit
	#if defined MainClass_OnGameModeInit
		forward MainClass_OnGameModeInit();
	#endif

	public OnGameModeExit()
	{
		MainClass_ExitScript();

		new ret = 1;
		#if defined MainClass_OnGameModeExit
			ret = MainClass_OnGameModeExit();
		#endif
		return ret;
	}
	#if defined _ALS_OnGameModeExit
		#undef OnGameModeExit
	#else
		#define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit MainClass_OnGameModeExit
	#if defined MainClass_OnGameModeExit
		forward MainClass_OnGameModeExit();
	#endif
#endif

public OnPlayerDisconnect(playerid, reason)
{
	//PLAYER CLASS
	MainClass_PlayerClass[playerid] = INVALID_CLASS_ID;

	new ret = 1;
	#if defined MainClass_OnPlayerDisconnect
		ret = MainClass_OnPlayerDisconnect(playerid, reason);
	#endif
	return ret;
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect MainClass_OnPlayerDisconnect
#if defined MainClass_OnPlayerDisconnect
	forward MainClass_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerRequestClass(playerid, classid)
{
	//SPAWN WORLDS //SPAWN INTERIORS
	if(MainClass_SpawnWorld[classid] != INVALID_VIRTUAL_WORLD_ID && MainClass_SpawnInterior[classid] != INVALID_INTERIOR_ID) { //Only handle classes created in this FS/GM
		//PLAYER CLASS
		MainClass_PlayerClass[playerid] = classid;
	} else {
		//PLAYER CLASS
		MainClass_PlayerClass[playerid] = INVALID_CLASS_ID;
	}

	new ret = 1;
	#if defined MainClass_OnPlayerRequestClass
		ret = MainClass_OnPlayerRequestClass(playerid, classid);
	#endif
	return ret;
}
#if defined _ALS_OnPlayerRequestClass
	#undef OnPlayerRequestClass
#else
	#define _ALS_OnPlayerRequestClass
#endif
#define OnPlayerRequestClass MainClass_OnPlayerRequestClass
#if defined MainClass_OnPlayerRequestClass
	forward MainClass_OnPlayerRequestClass(playerid, classid);
#endif

public OnPlayerSpawn(playerid)
{
	 //PLAYER CLASS
	if(MainClass_PlayerClass[playerid] != INVALID_CLASS_ID) { //Only handle classes created in this FS/GM
		//SPAWN WORLDS
		SetPlayerVirtualWorld(playerid, MainClass_SpawnWorld[MainClass_PlayerClass[playerid]]);

		//SPAWN INTERIORS
		SetPlayerInterior(playerid, MainClass_SpawnInterior[MainClass_PlayerClass[playerid]]);
	}

	new ret = 1;
	#if defined MainClass_OnPlayerSpawn
		ret = MainClass_OnPlayerSpawn(playerid);
	#endif
	return ret;
}
#if defined _ALS_OnPlayerSpawn
	#undef OnPlayerSpawn
#else
	#define _ALS_OnPlayerSpawn
#endif
#define OnPlayerSpawn MainClass_OnPlayerSpawn
#if defined MainClass_OnPlayerSpawn
	forward MainClass_OnPlayerSpawn(playerid);
#endif

//========================================HOOKED FUNCTIONS========================================
stock MainClass_AddPlayerClassEx(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle,
weapon1 = 0, weapon1_ammo = 0, weapon2 = 0, weapon2_ammo = 0, weapon3 = 0, weapon3_ammo = 0, worldid = VIRTUAL_WORLD_NORMAL, interiorid = INTERIOR_NORMAL) {
	new classid = AddPlayerClassEx(teamid, modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);

	//SPAWN WORLDS
	MainClass_SpawnWorld[classid] = worldid;

	//SPAWN INTERIOR
	MainClass_SpawnInterior[classid] = interiorid;

	return classid;
}
#if defined _ALS_AddPlayerClassEx
	#undef AddPlayerClassEx
#else
	#define _ALS_AddPlayerClassEx
#endif
#define AddPlayerClassEx MainClass_AddPlayerClassEx

stock MainClass_AddPlayerClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle,
weapon1 = 0, weapon1_ammo = 0, weapon2 = 0, weapon2_ammo = 0, weapon3 = 0, weapon3_ammo = 0, teamid = NO_TEAM, worldid = VIRTUAL_WORLD_NORMAL, interiorid = INTERIOR_NORMAL) {
	return AddPlayerClassEx(teamid, modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo, worldid, interiorid);
}
#if defined _ALS_AddPlayerClass
	#undef AddPlayerClass
#else
	#define _ALS_AddPlayerClass
#endif
#define AddPlayerClass MainClass_AddPlayerClass
