#if defined _mainplayer_included
	#endinput
#endif
#define _mainplayer_included

// CLEAR CHAT
/**
 * -DESCRIPTION:
 * 		-Clears a player's chat.
 * -PARAMETERS:
 * 		-playerid: The ID of the player to clear the chat of.
 * -RETURN VALUES:
 * 		-1: The function executed successfully.
 * 		-0: The function failed to execute. An invalid playerid was given.
 */
// native ClearChat(playerid); // Fake native
stock ClearChat(playerid) {
	if(IsPlayerConnected(playerid)) {
		for(new line = 0; line < 100; line++) {
			SendClientMessage(playerid, -1, " ");
		}
		return 1;
	}
	return 0;
}

// CLEAR KILLFEED
/**
 * -DESCRIPTION:
 * 		-Clears a player's killfeed.
 * -PARAMETERS:
 * 		-playerid: The ID of the player to clear the killfeed of.
 * -RETURN VALUES:
 * 		-1: The function executed successfully.
 * 		-0: The function failed to execute. An invalid playerid was given.
 */
// native ClearKillFeed(playerid); // Fake native
stock ClearKillFeed(playerid) {
	if(IsPlayerConnected(playerid)) {
		for(new death = 0; death < 5; death++) {
			SendDeathMessageToPlayer(playerid, MAX_PLAYERS, MAX_PLAYERS, 255);
		}
		return 1;
	}
	return 0;
}

// CLEAR GAMETEXTS
/**
 * -DESCRIPTION:
 * 		-Clears all gamtexts on a player's screen.
 * -PARAMETERS:
 * 		-playerid: The ID of the player to clear the gametexts of.
 * -RETURN VALUES:
 * 		-1: The function executed successfully.
 * 		-0: The function failed to execute. An invalid playerid was given.
 */
// native ClearGameTexts(playerid); // Fake native
stock ClearGameTexts(playerid) {
	if(IsPlayerConnected(playerid)) {
		GameTextForPlayer(playerid, " ", 100, 0);
		GameTextForPlayer(playerid, " ", 100, 1);
		GameTextForPlayer(playerid, " ", 100, 2);
		GameTextForPlayer(playerid, " ", 100, 3);
		GameTextForPlayer(playerid, " ", 100, 4);
		GameTextForPlayer(playerid, " ", 100, 5);
		GameTextForPlayer(playerid, " ", 100, 6);
		return 1;
	}
	return 0;
}

// RETURN PLAYER NAME AND ID
/**
 * -DESCRIPTION:
 * 		-Returns a string with a player's name and ID.
 * -PARAMETERS:
 * 		-playerid: The ID of the player to return the player name and ID of.
 * -RETURN VALUES:
 * 		-string with player name and ID: The function executed successfully.
 */
// native ReturnPlayerNameAndID(playerid); // Fake native
stock ReturnPlayerNameAndID(playerid) {
	new name[MAX_PLAYER_NAME + 1], output[MAX_PLAYER_NAME + 5 + 3 + 1 + 1];
	GetPlayerName(playerid, name, sizeof(name));
	format(output, sizeof(output), "%s (ID:%d)", name, playerid);
	return output;
}

// PLAY SOUND FOR PLAYERS IN RANGE
/**
 * -DESCRIPTION:
 * 		-Plays a sound for all players within a given range.
 * -PARAMETERS:
 * 		-soundid: The ID of the sound to play.
 * 		-Float:x: The X coordinate for the sound to play at.
 * 		-Float:y: The Y coordinate for the sound to play at.
 * 		-Float:z: The Z coordinate for the sound to play at.
 * 		-Float:range: The distance from the point players must be within for the sound to play.
 * 		 	-Defaults to 50.0.
 * 		-worldid: The ID of the virtual world players must be in for the sound to play.
 * 		 	-Defaults to VIRTUAL_WORLD_NORMAL.
 * 		-interiorid: The ID of the interior players must be in for the sound to play.
 * 		 	-Defaults to INTERIOR_NORMAL.
 * -RETURN VALUES:
 * 		-1: The function executed successfully.
 */
// native PlaySoundForPlayersInRange(soundid, Float:x, Float:y, Float:z, Float:range, interiorid = INTERIOR_NORMAL, worldid = VIRTUAL_WORLD_NORMAL); // Fake native
stock PlaySoundForPlayersInRange(soundid, Float:x, Float:y, Float:z, Float:range = 50.0, worldid = VIRTUAL_WORLD_NORMAL, interiorid = INTERIOR_NORMAL) {
	for(new playerid = 0, highestPlayerid = GetPlayerPoolSize(); playerid <= highestPlayerid; playerid++) {
		if(IsPlayerConnected(playerid) && GetPlayerInterior(playerid) == interiorid && worldid == GetPlayerVirtualWorld(playerid) && IsPlayerInRangeOfPoint(playerid, range, x, y, z)) {
			PlayerPlaySound(playerid, soundid, x, y, z);
		}
	}
	return 1;
}

// IS PLAYER IN NORMAL WORLD
/**
 * -DESCRIPTION:
 * 		-Get whether a player is in the default world.
 * -PARAMETERS:
 * 		-playerid: The ID of the player to get whether he is in the default world.
 * -RETURN VALUES:
 * 		-true: The function executed successfully. The player is in the default world.
 * 		-false:
 * 			-The function executed successfully. The player is not in the default world.
 * 			-The function failed to execute. An invalid playerid was given.
 * -NOTES:
 * 		-Uses the 'Normal' naming scheme instead of the 'Default' naming scheme, to be in line with the naming scheme used by SA-MP for e.g. fighting styles.
 */
// native bool:IsPlayerInNormalWorld(playerid); // Fake native
stock bool:IsPlayerInNormalWorld(playerid) {
	if(IsPlayerConnected(playerid)) {
		if(GetPlayerVirtualWorld(playerid) == VIRTUAL_WORLD_NORMAL && GetPlayerInterior(playerid) == INTERIOR_NORMAL) {
			return true;
		}
	}
	return false;
}

// ON PLAYER VIRTUAL WORLD CHANGE
/**
 * -DESCRIPTION:
 * 		-Gets called when a player changes virtual worlds.
 * -PARAMETERS:
 * 		-playerid: The ID of the player that changed virtual worlds.
 * 		-newvirtualworldid: The virtual world the player is in now.
 * 		-oldvirtualworldid: The virtual world the player was in before.
 * -RETURN VALUES:
 * 		-This callback doesn't handle returns.
 * -NOTES:
 * 		-Doesn't get called when the player is intializing (change from INVALID_VIRTUAL_WORLD_ID to a valid virtual world).
 * 		-OnPlayerUpdate hooked instead of hooking SetPlayerVirtualWorld, because there is a delay until the player actually changes virtual worlds.
 * 		-The library must be included in the gamemode for this callback to work in any filterscripts!
 */
forward OnPlayerVirtualWorldChange(playerid, newvirtualworldid, oldvirtualworldid);
#if !defined FILTERSCRIPT
	static MainPlayer_ChangeWorld[MAX_PLAYERS] = {INVALID_VIRTUAL_WORLD_ID, ...};
#endif

// PAUSE
/**
 * -DESCRIPTION:
 * 		-Store whether a player is paused and the last tick count when that player was still unpaused.
 * 		-Use a timer to periodically check whether each player is paused or not.
 */
// #if !defined FILTERSCRIPT
// 	static bool:MainPlayer_Paused[MAX_PLAYERS] = {false, ...};
// 	static MainPlayer_PauseTickCount[MAX_PLAYERS] = {0, ...};
// 	static MainPlayer_PauseTimer = INVALID_TIMER_ID;
// #endif

// IS PLAYER PAUSED
/**
 * -DESCRIPTION:
 * 		-Get whether a player is paused.
 * -PARAMETERS:
 * 		-playerid: The ID of the player to get whether he is paused.
 * -RETURN VALUES:
 * 		-true: The function executed successfully. The player is paused.
 * 		-false:
 * 			-The function executed successfully. The player is not paused.
 * 			-The function failed to execute. An invalid playerid was given.
 */
// native bool:IsPlayerPaused(playerid); // Fake native
// #if !defined FILTERSCRIPT
// 	#if !defined IsPlayerPaused
// 		stock bool:IsPlayerPaused(playerid) {
// 			if(IsPlayerConnected(playerid)) {
// 				// PAUSE
// 				return MainPlayer_Paused[playerid];
// 			}
// 			return false;
// 		}
// 	#endif
// #endif

// GET PLAYER PAUSED TIME
/**
 * -DESCRIPTION:
 * 		-Get the time a player has been paused for in milliseconds.
 * -PARAMETERS:
 * 		-playerid: The ID of the player to get the time he has been paused for in milliseconds of.
 * -RETURN VALUES:
 * 		-valid time: The function executed successfully.
 * 		-0:
 * 			-The function executed successfully. The player is not paused.
 * 			-The function failed to execute. An invalid playerid was given.
 */
// native GetPlayerPausedTime(playerid); // Fake native
// #if !defined FILTERSCRIPT
// 	#if !defined GetPlayerPausedTime
// 		stock GetPlayerPausedTime(playerid) {
// 			// PAUSE
// 			if(IsPlayerConnected(playerid) && MainPlayer_Paused[playerid]) {
// 				return GetTickCount() - MainPlayer_PauseTickCount[playerid];
// 			}
// 			return 0;
// 		}
// 	#endif
// #endif

// ON PLAYER PAUSE
/**
 * -DESCRIPTION:
 * 		-Gets called when a player pauses the game (opens the game menu or presses ALT-TAB).
 * -PARAMETERS:
 * 		-playerid: The ID of the player that paused the game.
 * -RETURN VALUES:
 * 		-This callback doesn't handle returns.
 * -NOTES:
 * 		-Doesn't get called when the player is intializing, dead or in class selection, due to the way OnPlayerUpdate works.
 * 		-NPCs are ignored as these can never pause.
 * 		-The maximum interval between OnPlayerUpdate calls is 1 second. So, to prevent faulty calls a margin of 1 second is added to this interval to a total of 2 seconds.
 * 		-The library must be included in the gamemode for this callback to work in any filterscripts!
 */
// forward OnPlayerPause(playerid);

// ON PLAYER UNPAUSE
/**
 * -DESCRIPTION:
 * 		-Gets called when a player unpauzes the game (closes the game menu).
 * -PARAMETERS:
 * 		-playerid: The ID of the player that unpaused the game.
 * -RETURN VALUES:
 * 		-This callback doesn't handle returns.
 * -NOTES:
 * 		-Doesn't get called when the player is intializing, dead or in class selection, due to the way OnPlayerUpdate works.
 * 		-NPCs are ignored as these can never pause.
 * 		-The maximum interval between OnPlayerUpdate calls is 1 second. So, to prevent faulty calls a margin of 1 second is added to this interval to a total of 2 seconds.
 * 		-The library must be included in the gamemode for this callback to work in any filterscripts!
 */
// forward OnPlayerUnpause(playerid);

// ========================================INTERNAL FUNCTIONS========================================
static MainPlayer_InitScript() {
	for(new playerid = 0; playerid < MAX_PLAYERS; playerid++) {
		#if !defined FILTERSCRIPT
			// ON PLAYER VIRTUAL WORLD CHANGE
			MainPlayer_ChangeWorld[playerid] = INVALID_VIRTUAL_WORLD_ID;

			// PAUSE
			// MainPlayer_Paused[playerid] = false;
			// MainPlayer_PauseTickCount[playerid] = GetTickCount();
		#endif
	}

	// #if !defined FILTERSCRIPT
	// 	// PAUSE
	// 	MainPlayer_PauseTimer = SetTimer("MainPlayer_CheckPlayersPaused", 1000, true);
	// #endif
}

static MainPlayer_ExitScript() {
	for(new playerid = 0; playerid < MAX_PLAYERS; playerid++) {
		#if !defined FILTERSCRIPT
			// ON PLAYER VIRTUAL WORLD CHANGE
			MainPlayer_ChangeWorld[playerid] = INVALID_VIRTUAL_WORLD_ID;

			// PAUSE
			// MainPlayer_Paused[playerid] = false;
			// MainPlayer_PauseTickCount[playerid] = 0;
		#endif
	}

	// #if !defined FILTERSCRIPT
	// 	// PAUSE
	// 	KillTimer(MainPlayer_PauseTimer);
	// 	MainPlayer_PauseTimer = INVALID_TIMER_ID;
	// #endif
}

// ========================================HOOKED CALLBACKS========================================
#if defined FILTERSCRIPT
	public OnFilterScriptInit()
	{
		MainPlayer_InitScript();

		new ret = 1;
		#if defined MainPlayer_OnFilterScriptInit
			ret = MainPlayer_OnFilterScriptInit();
		#endif
		return ret;
	}
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit MainPlayer_OnFilterScriptInit
	#if defined MainPlayer_OnFilterScriptInit
		forward MainPlayer_OnFilterScriptInit();
	#endif

	public OnFilterScriptExit()
	{
		MainPlayer_ExitScript();

		new ret = 1;
		#if defined MainPlayer_OnFilterScriptExit
			ret = MainPlayer_OnFilterScriptExit();
		#endif
		return ret;
	}
	#if defined _ALS_OnFilterScriptExit
		#undef OnFilterScriptExit
	#else
		#define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit MainPlayer_OnFilterScriptExit
	#if defined MainPlayer_OnFilterScriptExit
		forward MainPlayer_OnFilterScriptExit();
	#endif
#else
	public OnGameModeInit()
	{
		MainPlayer_InitScript();

		new ret = 1;
		#if defined MainPlayer_OnGameModeInit
			ret = MainPlayer_OnGameModeInit();
		#endif
		return ret;
	}
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit MainPlayer_OnGameModeInit
	#if defined MainPlayer_OnGameModeInit
		forward MainPlayer_OnGameModeInit();
	#endif

	public OnGameModeExit()
	{
		MainPlayer_ExitScript();

		new ret = 1;
		#if defined MainPlayer_OnGameModeExit
			ret = MainPlayer_OnGameModeExit();
		#endif
		return ret;
	}
	#if defined _ALS_OnGameModeExit
		#undef OnGameModeExit
	#else
		#define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit MainPlayer_OnGameModeExit
	#if defined MainPlayer_OnGameModeExit
		forward MainPlayer_OnGameModeExit();
	#endif
#endif

// public OnPlayerConnect(playerid)
// {
// 	#if !defined FILTERSCRIPT
// 		// PAUSE
// 		MainPlayer_Paused[playerid] = false;
// 		MainPlayer_PauseTickCount[playerid] = GetTickCount();
// 	#endif

// 	new ret = 1;
// 	#if defined MainPlayer_OnPlayerConnect
// 		ret = MainPlayer_OnPlayerConnect(playerid);
// 	#endif
// 	return ret;
// }
// #if defined _ALS_OnPlayerConnect
// 	#undef OnPlayerConnect
// #else
// 	#define _ALS_OnPlayerConnect
// #endif
// #define OnPlayerConnect MainPlayer_OnPlayerConnect
// #if defined MainPlayer_OnPlayerConnect
// 	forward MainPlayer_OnPlayerConnect(playerid);
// #endif

public OnPlayerDisconnect(playerid, reason)
{
	#if !defined FILTERSCRIPT
		// ON PLAYER VIRTUAL WORLD CHANGE
		MainPlayer_ChangeWorld[playerid] = INVALID_VIRTUAL_WORLD_ID;

		// PAUSE
		// MainPlayer_Paused[playerid] = false;
		// MainPlayer_PauseTickCount[playerid] = 0;
	#endif

	new ret = 1;
	#if defined MainPlayer_OnPlayerDisconnect
		ret = MainPlayer_OnPlayerDisconnect(playerid, reason);
	#endif
	return ret;
}
#if defined _ALS_OnPlayerDisconnect
	#undef OnPlayerDisconnect
#else
	#define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect MainPlayer_OnPlayerDisconnect
#if defined MainPlayer_OnPlayerDisconnect
	forward MainPlayer_OnPlayerDisconnect(playerid, reason);
#endif

public OnPlayerUpdate(playerid)
{
	#if !defined FILTERSCRIPT
		// ON PLAYER VIRTUAL WORLD CHANGE
		new newWorld = GetPlayerVirtualWorld(playerid);
		new oldWorld = MainPlayer_ChangeWorld[playerid];
		if(newWorld != oldWorld) {
			MainPlayer_ChangeWorld[playerid] = newWorld;

			// Don't call when the player is initializing
			if(oldWorld != INVALID_VIRTUAL_WORLD_ID) {
				CallRemoteFunction("OnPlayerVirtualWorldChange", "iii", playerid, newWorld, oldWorld);
			}
		}

		// PAUSE
		// MainPlayer_PauseTickCount[playerid] = GetTickCount();
	#endif

	new ret = 1;
	#if defined MainPlayer_OnPlayerUpdate
		ret = MainPlayer_OnPlayerUpdate(playerid);
	#endif
	return ret;
}
#if defined _ALS_OnPlayerUpdate
	#undef OnPlayerUpdate
#else
	#define _ALS_OnPlayerUpdate
#endif
#define OnPlayerUpdate MainPlayer_OnPlayerUpdate
#if defined MainPlayer_OnPlayerUpdate
	forward MainPlayer_OnPlayerUpdate(playerid);
#endif

// ========================================HOOKED FUNCTIONS========================================
// SET PLAYER POSITION
/**
 * -DESCRIPTION:
 * 		-Set a player's position and preload streamed items.
 * -PARAMETERS:
 * 		-playerid: The ID of the player to set the position of.
 * 		-Float:x: The X coordinate to position the player at.
 * 		-Float:y: The Y coordinate to position the player at.
 * 		-Float:z: The Z coordinate to position the player at.
 * 		-bool:preload: Whether to preload streamed items or not.
 * 		 	-Defaults to false.
 * -RETURN VALUES:
 * 		-1: The function executed successfully.
 * 		-0: The function failed to execute. An invalid playerid was given.
 * -NOTES:
 * 		-The streamer include must be loaded before this include in order for the preloading to work.
 */
// native SetPlayerPos(playerid, Float:x, Float:y, Float:z, bool:preload = false); // Fake native
stock MainPlayer_SetPlayerPos(playerid, Float:x, Float:y, Float:z, bool:preload = false) {
	#if defined _streamer_included
		if(preload) {
			Streamer_UpdateEx(playerid, x, y, z, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid));
		}
	#else
		#pragma unused preload
	#endif
	return SetPlayerPos(playerid, x, y, z);
}
#if defined _ALS_SetPlayerPos
	#undef SetPlayerPos
#else
	#define _ALS_SetPlayerPos
#endif
#define SetPlayerPos MainPlayer_SetPlayerPos

// ========================================TIMERS========================================
// #if !defined FILTERSCRIPT
// 	// PAUSE
// 	forward MainPlayer_CheckPlayersPaused();
// 	public MainPlayer_CheckPlayersPaused() {
// 		for(new playerid = 0, highestPlayerid = GetPlayerPoolSize(); playerid <= highestPlayerid; playerid++) {
// 			new playerState = GetPlayerState(playerid);

// 			// OnPlayerUpdate isn't called when the player is initializing, dead or in class selection
// 			if(IsPlayerConnected(playerid) && !IsPlayerNPC(playerid) && playerState != PLAYER_STATE_WASTED && playerState != PLAYER_STATE_NONE) {
// 				new bool:playerInGame = true;
// 				if(GetTickCount() - MainPlayer_PauseTickCount[playerid] > 2000) { // 2 second interval
// 					playerInGame = false;
// 				}
// 				if(!playerInGame && !MainPlayer_Paused[playerid]) {
// 					MainPlayer_Paused[playerid] = true;
// 					// ON PLAYER PAUSE
// 					CallRemoteFunction("OnPlayerPause", "i", playerid);
// 				} else if(playerInGame && MainPlayer_Paused[playerid]) {
// 					MainPlayer_Paused[playerid] = false;
// 					// ON PLAYER UNPAUSE
// 					CallRemoteFunction("OnPlayerUnpause", "i", playerid);
// 				}
// 			}
// 		}
// 	}
// #endif