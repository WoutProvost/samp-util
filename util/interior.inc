#if defined _maininterior_included
	#endinput
#endif
#define _maininterior_included

// INTERIOR AMOUNT LIMIT
/**
 * -DESCRIPTION:
 * 		-Defines the interior amount limit.
 */
#define MAX_INTERIORS						256

// INVALID INTERIOR
/**
 * -DESCRIPTION:
 * 		-Defines an invalid interior ID.
 */
#define INVALID_INTERIOR_ID					-1

// DEFAULT INTERIOR
/**
 * -DESCRIPTION:
 * 		-Defines the default interior used by SA-MP.
 * -NOTES:
 * 		-Uses the '_NORMAL' naming scheme instead of the '_DEFAULT' naming scheme, to be in line with the naming scheme used by SA-MP for e.g. fighting styles.
 */
#define INTERIOR_NORMAL						0