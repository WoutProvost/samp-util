#if defined _maintime_included
	#endinput
#endif
#define _maintime_included

// DEFAULT TIME
/**
 * -DESCRIPTION:
 * 		-Defines the default hours and minutes used by SA-MP.
 * -NOTES:
 * 		-Uses the '_NORMAL' naming scheme instead of the '_DEFAULT' naming scheme, to be in line with the naming scheme used by SA-MP for e.g. fighting styles.
 */
#define TIME_HOUR_NORMAL					12
#define TIME_MINUTE_NORMAL					0

// GET WORLD TIME
/**
 * -DESCRIPTION:
 * 		-Get the world time.
 * -PARAMETERS:
 * 		-This function has no parameters.
 * -RETURN VALUES:
 * 		-worldtime: The function executed successfully.
 */
// native GetWorldTime(); // Fake native
#if !defined GetWorldTime
	stock GetWorldTime() {
		new buffer[2 + 1];
		GetConsoleVarAsString("worldtime", buffer, sizeof(buffer));
		return strval(buffer);
	}
#endif