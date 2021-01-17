#if defined _mainvirtualworld_included
	#endinput
#endif
#define _mainvirtualworld_included

// VIRTUAL WORLD AMOUNT LIMIT
/**
 * -DESCRIPTION:
 * 		-Defines the virtual world amount limit (2147483647).
 */
#define MAX_VIRTUAL_WORLDS					cellmax

// INVALID VIRTUAL WORLD
/**
 * -DESCRIPTION:
 * 		-Defines an invalid virtual world ID.
 */
#define INVALID_VIRTUAL_WORLD_ID			-1

// DEFAULT VIRTUAL WORLD
/**
 * -DESCRIPTION:
 * 		-Defines the default virtual world used by SA-MP.
 * -NOTES:
 * 		-Uses the '_NORMAL' naming scheme instead of the '_DEFAULT' naming scheme, to be in line with the naming scheme used by SA-MP for e.g. fighting styles.
 * 		-Items like objects, checkpoints, pickups, mapicons, etc. are only present in this world.
 */
#define VIRTUAL_WORLD_NORMAL				0