#if defined _mainweapon_included
	#endinput
#endif
#define _mainweapon_included

// WEAPON AMOUNT LIMIT
/**
 * -DESCRIPTION:
 * 		-Defines the weapon amount limit.
 */
#define MAX_WEAPONS							47

// INVALID WEAPON
/**
 * -DESCRIPTION:
 * 		-Defines an invalid weapon ID.
 */
#define INVALID_WEAPON_ID					-1

// WEAPON ID
/**
 * -DESCRIPTION:
 * 		-Defines some missing weapon ID constants.
 */
#define WEAPON_FISTS						0
#define WEAPON_NIGHTVISION					44
#define WEAPON_INFRARED						45

// NAMES
/**
 * -DESCRIPTION:
 * 		-Weapon names.
 */
#define MAX_WEAPON_NAME						31
static const MainWeapon_WeaponNames[][] = {
	"Fist", "Brass Knuckles", // Slot 0
	"Golf Club", "Nightstick", "Knife", "Baseball Bat", "Shovel", "Pool Cue", "Katana", "Chainsaw", // Slot 1
	"Purple Dildo", "Dildo", "Vibrator", "Silver Vibrator", "Flowers", "Cane", // Slot 10
	"Grenade", "Tear Gas", "Molotov Cocktail", // Slot 8 + see below
	" ", " ", " ", // Invalid
	"Colt 45/9mm", "Silenced Colt 45/9mm", "Deagle/Desert Eagle", // Slot 2
	"Shotgun", "Sawnoff Shotgun", "SPAS-12/Combat Shotgun", // Slot 3
	"Micro SMG/Uzi", "MP5", // Slot 4 + see below
	"AK-47", "M4", // Slot 5
	"Tec-9", // Slot 4 + see above
	"Country Rifle", "Sniper Rifle", // Slot 6
	"RPG/Rocket Launcher", "Heat-Seeking Rocket Launcher", "Flamethrower", "Minigun", // Slot 7
	"Satchel Charge", // Slot 8 + see above
	"Detonator", // Slot 12
	"Spray Can", "Fire Extinguisher", "Camera", // Slot 9
	"Night Vision Goggles", "Infrared/Thermal Vision Goggles", "Parachute" // Slot 11
};

// IS VALID WEAPON
/**
 * -DESCRIPTION:
 * 		-Get whether a weapon ID is valid.
 * -PARAMETERS:
 * 		-weaponid: The ID of the weapon to get whether it is valid.
 * -RETURN VALUES:
 * 		-true: The function executed successfully. The weapon ID is valid.
 * 		-false: The function executed successfully. The weapon ID is not valid.
 */
// native bool:IsValidWeapon(weaponid); // Fake native
stock bool:IsValidWeapon(weaponid) {
	if((weaponid >= 0 && weaponid <= 18) || (weaponid >= 22 && weaponid < MAX_WEAPONS)) {
		return true;
	}
	return false;
}

// MODELS
/**
 * -DESCRIPTION:
 * 		-Weapon models.
 */
static const MainWeapon_WeaponModels[] = {
	INVALID_MODEL_ID, 331, // Slot 0
	333, 334, 335, 336, 337, 338, 339, 341, // Slot 1
	321, 322, 323, 324, 325, 326, // Slot 10
	342, 343, 344, // Slot 8 + see below
	INVALID_MODEL_ID, INVALID_MODEL_ID, INVALID_MODEL_ID, // Invalid
	346, 347, 348, // Slot 2
	349, 350, 351, // Slot 3
	352, 353, // Slot 4 + see below
	355, 356, // Slot 5
	372, // Slot 4 + see above
	357, 358, // Slot 6
	359, 360, 361, 362, // Slot 7
	363, // Slot 8 + see above
	364, // Slot 12
	365, 366, 367, // Slot 9
	368, 369, 371 // Slot 11
};

// GET WEAPON MODEL
/**
 * -DESCRIPTION:
 * 		-Get a weapon's modelid.
 * -PARAMETERS:
 * 		-weaponid: The ID of the weapon to get the modelid of.
 * -RETURN VALUES:
 * 		-valid modelid: The function executed successfully.
 * 		-INVALID_MODEL_ID: The function failed to execute. An invalid weaponid was given.
 */
// native GetWeaponModel(weaponid); // Fake native
stock GetWeaponModel(weaponid) {
	if(weaponid >= 0 && weaponid < MAX_WEAPONS) {
		return MainWeapon_WeaponModels[weaponid];
	}
	return INVALID_MODEL_ID;
}

// IS WEAPON SPRINT ALLOWED
/**
 * -DESCRIPTION:
 * 		-Get whether a weapon ID allows sprinting.
 * -PARAMETERS:
 * 		-weaponid: The ID of the weapon to get whether it allows sprinting.
 * -RETURN VALUES:
 * 		-true: The function executed successfully. The weapon ID allows sprinting.
 * 		-false: The function executed successfully. The weapon ID does not allow sprinting.
 */
// native bool:IsWeaponSprintAllowed(weaponid); // Fake native
stock bool:IsWeaponSprintAllowed(weaponid) {
	switch(weaponid) {
		case WEAPON_FISTS: return true;
		case WEAPON_BRASSKNUCKLE: return true;
		case WEAPON_GOLFCLUB: return true;
		case WEAPON_NITESTICK: return true;
		case WEAPON_KNIFE: return true;
		case WEAPON_BAT: return false;
		case WEAPON_SHOVEL: return false;
		case WEAPON_POOLSTICK: return false;
		case WEAPON_KATANA: return true;
		case WEAPON_CHAINSAW: return false;
		case WEAPON_DILDO: return true;
		case WEAPON_DILDO2: return true;
		case WEAPON_VIBRATOR: return true;
		case WEAPON_VIBRATOR2: return true;
		case WEAPON_FLOWER: return true;
		case WEAPON_CANE: return true;
		case WEAPON_GRENADE: return true;
		case WEAPON_TEARGAS: return true;
		case WEAPON_MOLTOV: return true;
		case 19: return false;
		case 20: return false;
		case 21: return false;
		case WEAPON_COLT45: return true;
		case WEAPON_SILENCED: return true;
		case WEAPON_DEAGLE: return true;
		case WEAPON_SHOTGUN: return false;
		case WEAPON_SAWEDOFF: return true;
		case WEAPON_SHOTGSPA: return false;
		case WEAPON_UZI: return true;
		case WEAPON_MP5: return true;
		case WEAPON_AK47: return false;
		case WEAPON_M4: return false;
		case WEAPON_TEC9: return true;
		case WEAPON_RIFLE: return false;
		case WEAPON_SNIPER: return false;
		case WEAPON_ROCKETLAUNCHER: return false;
		case WEAPON_HEATSEEKER: return false;
		case WEAPON_FLAMETHROWER: return false;
		case WEAPON_MINIGUN: return false;
		case WEAPON_SATCHEL: return true;
		case WEAPON_BOMB: return true;
		case WEAPON_SPRAYCAN: return true;
		case WEAPON_FIREEXTINGUISHER: return true;
		case WEAPON_CAMERA: return true;
		case WEAPON_NIGHTVISION: return true;
		case WEAPON_INFRARED: return true;
		case WEAPON_PARACHUTE: return true;
	}
	return false;
}

// IS WEAPON CROUCH ALLOWED
/**
 * -DESCRIPTION:
 * 		-Get whether a weapon ID allows crouching.
 * -PARAMETERS:
 * 		-weaponid: The ID of the weapon to get whether it allows crouching.
 * -RETURN VALUES:
 * 		-true: The function executed successfully. The weapon ID allows crouching.
 * 		-false: The function executed successfully. The weapon ID does not allow crouching.
 */
// native bool:IsWeaponCrouchAllowed(weaponid); // Fake native
stock bool:IsWeaponCrouchAllowed(weaponid) {
	switch(weaponid) {
		case WEAPON_FISTS: return true;
		case WEAPON_BRASSKNUCKLE: return true;
		case WEAPON_GOLFCLUB: return true;
		case WEAPON_NITESTICK: return true;
		case WEAPON_KNIFE: return true;
		case WEAPON_BAT: return true;
		case WEAPON_SHOVEL: return true;
		case WEAPON_POOLSTICK: return true;
		case WEAPON_KATANA: return true;
		case WEAPON_CHAINSAW: return true;
		case WEAPON_DILDO: return true;
		case WEAPON_DILDO2: return true;
		case WEAPON_VIBRATOR: return true;
		case WEAPON_VIBRATOR2: return true;
		case WEAPON_FLOWER: return true;
		case WEAPON_CANE: return true;
		case WEAPON_GRENADE: return false;
		case WEAPON_TEARGAS: return false;
		case WEAPON_MOLTOV: return false;
		case 19: return false;
		case 20: return false;
		case 21: return false;
		case WEAPON_COLT45: return true;
		case WEAPON_SILENCED: return true;
		case WEAPON_DEAGLE: return true;
		case WEAPON_SHOTGUN: return true;
		case WEAPON_SAWEDOFF: return true;
		case WEAPON_SHOTGSPA: return true;
		case WEAPON_UZI: return true;
		case WEAPON_MP5: return true;
		case WEAPON_AK47: return true;
		case WEAPON_M4: return true;
		case WEAPON_TEC9: return true;
		case WEAPON_RIFLE: return true;
		case WEAPON_SNIPER: return true;
		case WEAPON_ROCKETLAUNCHER: return false;
		case WEAPON_HEATSEEKER: return false;
		case WEAPON_FLAMETHROWER: return false;
		case WEAPON_MINIGUN: return false;
		case WEAPON_SATCHEL: return false;
		case WEAPON_BOMB: return true;
		case WEAPON_SPRAYCAN: return true;
		case WEAPON_FIREEXTINGUISHER: return false;
		case WEAPON_CAMERA: return false;
		case WEAPON_NIGHTVISION: return true;
		case WEAPON_INFRARED: return true;
		case WEAPON_PARACHUTE: return true;
	}
	return false;
}

// GET WEAPON DAMAGE
/**
 * -DESCRIPTION:
 * 		-Get a weapon's damage.
 * -PARAMETERS:
 * 		-weaponid: The ID of the weapon to get the damage of.
 * -RETURN VALUES:
 * 		-valid damage: The function executed successfully.
 * 		-0.0:
 * 			-The function executed successfully. The weaponid doesn't have a non-zero damage.
 * 			-The function failed to execute. An invalid weaponid was given.
 */
// native Float:GetWeaponDamage(weaponid); // Fake native
stock Float:GetWeaponDamage(weaponid) {
	new Float:damage = 0.0;
	switch(weaponid) {
		case WEAPON_FISTS: damage = 5.0;
		case WEAPON_BRASSKNUCKLE: damage = 5.0;
		case WEAPON_GOLFCLUB: damage = 5.0;
		case WEAPON_NITESTICK: damage = 5.0;
		case WEAPON_KNIFE: damage = 5.0;
		case WEAPON_BAT: damage = 5.0;
		case WEAPON_SHOVEL: damage = 5.0;
		case WEAPON_POOLSTICK: damage = 5.0;
		case WEAPON_KATANA: damage = 5.0;
		case WEAPON_CHAINSAW: damage = 5.0;
		case WEAPON_DILDO: damage = 5.0;
		case WEAPON_DILDO2: damage = 5.0;
		case WEAPON_VIBRATOR: damage = 5.0;
		case WEAPON_VIBRATOR2: damage = 5.0;
		case WEAPON_FLOWER: damage = 5.0;
		case WEAPON_CANE: damage = 5.0;
		case WEAPON_GRENADE: damage = 5.0;
		case WEAPON_TEARGAS: damage = 5.0;
		case WEAPON_MOLTOV: damage = 5.0;
		case 19: damage = 0.0;
		case 20: damage = 0.0;
		case 21: damage = 0.0;
		case WEAPON_COLT45: damage = 8.25;
		case WEAPON_SILENCED: damage = 13.2;
		case WEAPON_DEAGLE: damage = 46.2;
		case WEAPON_SHOTGUN: damage = 30.0;
		case WEAPON_SAWEDOFF: damage = 30.0;
		case WEAPON_SHOTGSPA: damage = 30.0;
		case WEAPON_UZI: damage = 6.60;
		case WEAPON_MP5: damage = 8.25;
		case WEAPON_AK47: damage = 9.90;
		case WEAPON_M4: damage = 9.90;
		case WEAPON_TEC9: damage = 6.60;
		case WEAPON_RIFLE: damage = 24.8;
		case WEAPON_SNIPER: damage = 41.3;
		case WEAPON_ROCKETLAUNCHER: damage = 5.0;
		case WEAPON_HEATSEEKER: damage = 5.0;
		case WEAPON_FLAMETHROWER: damage = 5.0;
		case WEAPON_MINIGUN: damage = 46.2;
		case WEAPON_SATCHEL: damage = 5.0;
		case WEAPON_BOMB: damage = 5.0;
		case WEAPON_SPRAYCAN: damage = 5.0;
		case WEAPON_FIREEXTINGUISHER: damage = 5.0;
		case WEAPON_CAMERA: damage = 0.0;
		case WEAPON_NIGHTVISION: damage = 0.0;
		case WEAPON_INFRARED: damage = 0.0;
		case WEAPON_PARACHUTE: damage = 0.0;
	}
	return damage;
}

// GET WEAPON VEHICLE DAMAGE
/**
 * -DESCRIPTION:
 * 		-Get a weapon's vehicle damage.
 * -PARAMETERS:
 * 		-weaponid: The ID of the weapon to get the vehicle damage of.
 * -RETURN VALUES:
 * 		-valid damage: The function executed successfully.
 * 		-0.0: The function failed to execute. An invalid weaponid was given or the weaponid given is not a bullet weapon.
 * -NOTES:
 * 		-Values taken from weapon.dat singleplayer file. These are the actual damage values for vehicles. Multiply by 0.33 for player damage values.
 */
// native Float:GetWeaponVehicleDamage(weaponid); // Fake native
stock Float:GetWeaponVehicleDamage(weaponid) {
	new Float:damage = 0.0;
	switch(weaponid) {
		case WEAPON_COLT45: damage = 25.0;
		case WEAPON_SILENCED: damage = 40.0;
		case WEAPON_DEAGLE: damage = 140.0;
		case WEAPON_SHOTGUN: damage = 10.0;
		case WEAPON_SAWEDOFF: damage = 10.0;
		case WEAPON_SHOTGSPA: damage = 15.0;
		case WEAPON_UZI: damage = 20.0;
		case WEAPON_TEC9: damage = 20.0;
		case WEAPON_MP5: damage = 25.0;
		case WEAPON_AK47: damage = 30.0;
		case WEAPON_M4: damage = 30.0;
		case WEAPON_RIFLE: damage = 75.0;
		case WEAPON_SNIPER: damage = 125.0;
		case WEAPON_MINIGUN: damage = 140.0;
	}
	return damage;
}

// IS MELEE WEAPON
/**
 * -DESCRIPTION:
 * 		-Get whether a weapon is a melee weapon.
 * -PARAMETERS:
 * 		-weaponid: The ID of the weapon to get whether it is a melee weapon.
 * -RETURN VALUES:
 * 		-true: The function executed successfully. The weapon is a melee weapon.
 * 		-false: The function executed successfully. The weapon is not a melee weapon.
 */
// native bool:IsMeleeWeapon(weaponid); // Fake native
stock bool:IsMeleeWeapon(weaponid) {
	if(weaponid >= 0 && weaponid <= 15) {
		return true;
	}
	return false;
}

// ========================================HOOKED FUNCTIONS========================================
// GET WEAPON NAME
/**
 * -DESCRIPTION:
 * 		-Get a weapon's name.
 * -PARAMETERS:
 * 		-weaponid: The ID of the weapon to get the name of.
 * 		-name[]: An array into which to store the name, passed by reference.
 * 		-len: The length of the string that should be stored. Recommended to be MAX_WEAPON_NAME + 1.
 * -RETURN VALUES:
 * 		-name length: The function executed successfully.
 * 		-0: The function failed to execute. An invalid weaponid was given.
 * -NOTES:
 * 		-Works like GetPlayerName so that the name is stored in the given string parameter.
 * 		-This function does exist within the SA-MP server, but the names are not that great.
 * 		-Therefore we have hook it to get better names.
 */
// native GetWeaponName(weaponid, name[], len); // Fake native
stock MainWeapon_GetWeaponName(weaponid, name[], len) {
	if(weaponid >= 0 && weaponid < MAX_WEAPONS) {
		// NAMES
		return strmid(name, MainWeapon_WeaponNames[weaponid], 0, len, len);
	}
	return 0;
}
#if defined _ALS_GetWeaponName
	#undef GetWeaponName
#else
	#define _ALS_GetWeaponName
#endif
#define GetWeaponName MainWeapon_GetWeaponName