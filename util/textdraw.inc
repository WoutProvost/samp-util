#if defined _maintextdraw_included
	#endinput
#endif
#define _maintextdraw_included

// TEXT DRAW TEXT LIMIT
/**
 * -DESCRIPTION:
 * 		-Defines the text draw text limit.
 */
#define MAX_TEXT_DRAW_TEXT					1024

// TEXT DRAWS SHOWN LIMIT
/**
 * -DESCRIPTION:
 * 		-Defines the text draws shown limit.
 */
#define MAX_TEXT_DRAWS_SHOWN				MAX_TEXT_DRAWS+MAX_PLAYER_TEXT_DRAWS

// TEXT DRAW SPRITES SHOWN LIMIT
/**
 * -DESCRIPTION:
 * 		-Defines the text draw sprites shown limit.
 */
#define MAX_TEXT_DRAW_SPRITES_SHOWN			100

// PLAYER TEXT DRAW CREATE
/**
 * -DESCRIPTION:
 * 		-Creates a text draw for a single player.
 * -PARAMETERS:
 * 		-playerid: The ID of the player to create the player text draw for.
 * 		-Float:x: The X coordinate on the screen to create the player text draw at.
 * 		-Float:y: The Y coordinate on the screen to create the player text draw at.
 * 		-const text[]: The text to display in the player text draw, passed by reference.
 * -RETURN VALUES:
 * 		-PlayerText:valid player text draw id: The function executed successfully.
 * 		-PlayerText:0:
 * 			-The function executed successfully. The id of the player textdraw is 0.
 * 			-The function failed to execute. An invalid playerid was given.
 * -NOTES:
 * 		-The function that exists in the include files is called CreatePlayerTextDraw, which has an inconsistent name with the other player text draw functions. Therefore we define a proper consistent alias.
 */
// native PlayerText:PlayerTextDrawCreate(playerid, Float:x, Float:y, const text[]); // Fake native
#define PlayerTextDrawCreate				CreatePlayerTextDraw