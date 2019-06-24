#if defined _mainaudiostream_included
	#endinput
#endif
#define _mainaudiostream_included

//DURATION
/**
 * -DESCRIPTION:
 * 		-Automatically stops audio streams after they have finished playing.
 * -NOTES:
 * 		-When playing an audio stream for a player in a vehicle, the in-game radio is set to 'USER TRACK PLAYER'.
 * 		-This stays like this even when the audio stream is actively stopped and even after re-entering the vehicle.
 * 		-The solution is to stop the audio stream using a timer given the duration of the audio stream and play a set of sounds that have a special property of muting and unmuting the in-game radio.
 * 		-Sound IDs 1068 and 1069 have this special property, but it doesn't work if they are immediately played after each other, so an extra very short timer is necessary.
 * 		-An extra margin of a few seconds is added to the duration, because the audio stream doesn't always start playing immediately.
 * -CREDITS:
 * 		-Method found in The Godfather script: http://forum.sa-mp.com/showthread.php?t=7797
 * 		-Edited by Freaksken.
 */
static MainAudioStream_DurationTimer[MAX_PLAYERS] = {INVALID_TIMER_ID, ...};
static MainAudioStream_RadioFixTimer[MAX_PLAYERS] = {INVALID_TIMER_ID, ...};

//========================================INTERNAL FUNCTIONS========================================
static MainAudioStream_InitScript() {
	for(new playerid = 0; playerid < MAX_PLAYERS; playerid++) { //Using MAX_PLAYERS instead of GetPlayerPoolSize because we need to initialize the variables of all possible player IDs
		//DURATION
		MainAudioStream_DurationTimer[playerid] = INVALID_TIMER_ID;
		MainAudioStream_RadioFixTimer[playerid] = INVALID_TIMER_ID;
	}
}

static MainAudioStream_ExitScript() {
	for(new playerid = 0; playerid < MAX_PLAYERS; playerid++) { //Using MAX_PLAYERS instead of GetPlayerPoolSize because we need to reset the variables of all possible player IDs
		//DURATION
		KillTimer(MainAudioStream_DurationTimer[playerid]);
		MainAudioStream_DurationTimer[playerid] = INVALID_TIMER_ID;
		KillTimer(MainAudioStream_RadioFixTimer[playerid]);
		MainAudioStream_RadioFixTimer[playerid] = INVALID_TIMER_ID;
	}
}

//========================================HOOKED CALLBACKS========================================
#if defined FILTERSCRIPT
	public OnFilterScriptInit()
	{
		MainAudioStream_InitScript();

		new ret = 1;
		#if defined MainAudioStream_OFSI
			ret = MainAudioStream_OFSI();
		#endif
		return ret;
	}
	#if defined _ALS_OnFilterScriptInit
		#undef OnFilterScriptInit
	#else
		#define _ALS_OnFilterScriptInit
	#endif
	#define OnFilterScriptInit MainAudioStream_OFSI
	#if defined MainAudioStream_OFSI
		forward MainAudioStream_OFSI();
	#endif

	public OnFilterScriptExit()
	{
		MainAudioStream_ExitScript();

		new ret = 1;
		#if defined MainAudioStream_OFSE
			ret = MainAudioStream_OFSE();
		#endif
		return ret;
	}
	#if defined _ALS_OnFilterScriptExit
		#undef OnFilterScriptExit
	#else
		#define _ALS_OnFilterScriptExit
	#endif
	#define OnFilterScriptExit MainAudioStream_OFSE
	#if defined MainAudioStream_OFSE
		forward MainAudioStream_OFSE();
	#endif
#else
	public OnGameModeInit()
	{
		MainAudioStream_InitScript();

		new ret = 1;
		#if defined MainAudioStream_OnGameModeInit
			ret = MainAudioStream_OnGameModeInit();
		#endif
		return ret;
	}
	#if defined _ALS_OnGameModeInit
		#undef OnGameModeInit
	#else
		#define _ALS_OnGameModeInit
	#endif
	#define OnGameModeInit MainAudioStream_OnGameModeInit
	#if defined MainAudioStream_OnGameModeInit
		forward MainAudioStream_OnGameModeInit();
	#endif

	public OnGameModeExit()
	{
		MainAudioStream_ExitScript();

		new ret = 1;
		#if defined MainAudioStream_OnGameModeExit
			ret = MainAudioStream_OnGameModeExit();
		#endif
		return ret;
	}
	#if defined _ALS_OnGameModeExit
		#undef OnGameModeExit
	#else
		#define _ALS_OnGameModeExit
	#endif
	#define OnGameModeExit MainAudioStream_OnGameModeExit
	#if defined MainAudioStream_OnGameModeExit
		forward MainAudioStream_OnGameModeExit();
	#endif
#endif

//========================================HOOKED FUNCTIONS========================================
stock MainAudioStream_PlayAudioStream(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = 0, time = -1) {
	new ret = PlayAudioStreamForPlayer(playerid, url, posX, posY, posZ, distance, usepos);
	if(ret == 1) {
		//DURATION
		KillTimer(MainAudioStream_DurationTimer[playerid]);
		MainAudioStream_DurationTimer[playerid] = INVALID_TIMER_ID;
		if(MainAudioStream_RadioFixTimer[playerid] != INVALID_TIMER_ID) {
			MainAudioStream_RadioFix(playerid);
		}
		if(time != -1) {
			MainAudioStream_DurationTimer[playerid] = SetTimerEx("MainAudioStream_Duration", time + 2000, false, "d", playerid); //2 seconds extra
		}
	}
	return ret;
}
#if defined _ALS_PlayAudioStreamForPlayer
	#undef PlayAudioStreamForPlayer
#else
	#define _ALS_PlayAudioStreamForPlayer
#endif
#define PlayAudioStreamForPlayer MainAudioStream_PlayAudioStream

stock MainAudioStream_StopAudioStream(playerid) {
	//DURATION
	if(IsPlayerInAnyVehicle(playerid)) {
		PlayerPlaySound(playerid, 1068, 0.0, 0.0, 0.0);
		MainAudioStream_RadioFixTimer[playerid] = SetTimerEx("MainAudioStream_RadioFix", 50, false, "d", playerid);
	}
	KillTimer(MainAudioStream_DurationTimer[playerid]);
	MainAudioStream_DurationTimer[playerid] = INVALID_TIMER_ID;
	return StopAudioStreamForPlayer(playerid);
}
#if defined _ALS_StopAudioStreamForPlayer
	#undef StopAudioStreamForPlayer
#else
	#define _ALS_StopAudioStreamForPlayer
#endif
#define StopAudioStreamForPlayer MainAudioStream_StopAudioStream

//========================================TIMERS========================================
forward MainAudioStream_Duration(playerid);
public MainAudioStream_Duration(playerid) {
	//DURATION
	StopAudioStreamForPlayer(playerid);
	return 1;
}

forward MainAudioStream_RadioFix(playerid);
public MainAudioStream_RadioFix(playerid) {
	//DURATION
	PlayerPlaySound(playerid, 1069, 0.0, 0.0, 0.0);
	KillTimer(MainAudioStream_RadioFixTimer[playerid]);
	MainAudioStream_RadioFixTimer[playerid] = INVALID_TIMER_ID;
	return 1;
}