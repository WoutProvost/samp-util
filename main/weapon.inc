#if defined _mainweapon_included
	#endinput
#endif
#define _mainweapon_included

//INVALID WEAPON
/**
 * -DESCRIPTION:
 * 		-Defines an invalid weapon ID.
 */
#define INVALID_WEAPON_ID					-1

//NAMES
/**
 * -DESCRIPTION:
 * 		-Weapon names.
 */
#define MAX_WEAPON_NAME						31
static const MainWeapon_WeaponNames[][] = {
	"Fist", "Brass Knuckles", //Slot 0
	"Golf Club", "Nightstick", "Knife", "Baseball Bat", "Shovel", "Pool Cue", "Katana", "Chainsaw", //Slot 1
	"Purple Dildo", "Dildo", "Vibrator", "Silver Vibrator", "Flowers", "Cane", //Slot 10
	"Grenade", "Tear Gas", "Molotov Cocktail", //Slot 8 + see below
	" ", " ", " ", //Invalid
	"Colt 45/9mm", "Silenced Colt 45/9mm", "Deagle/Desert Eagle", //Slot 2
	"Shotgun", "Sawnoff Shotgun", "SPAS-12/Combat Shotgun", //Slot 3
	"Micro SMG/Uzi", "MP5", //Slot 4 + see below
	"AK-47", "M4", //Slot 5
	"Tec-9", //Slot 4 + see above
	"Country Rifle", "Sniper Rifle", //Slot 6
	"RPG/Rocket Launcher", "Heat-Seeking Rocket Launcher", "Flamethrower", "Minigun", //Slot 7
	"Satchel Charge", //Slot 8 + see above
	"Detonator", //Slot 12
	"Spray Can", "Fire Extinguisher", "Camera", //Slot 9
	"Night Vision Goggles", "Infrared/Thermal Vision Goggles", "Parachute" //Slot 11
};

//MODELS
/**
 * -DESCRIPTION:
 * 		-Weapon models.
 */
static const MainWeapon_WeaponModels[] = {
	INVALID_MODEL_ID, 331, //Slot 0
	333, 334, 335, 336, 337, 338, 339, 341, //Slot 1
	321, 322, 323, 324, 325, 326, //Slot 10
	342, 343, 344, //Slot 8 + see below
	INVALID_MODEL_ID, INVALID_MODEL_ID, INVALID_MODEL_ID, //Invalid
	346, 347, 348, //Slot 2
	349, 350, 351, //Slot 3
	352, 353, //Slot 4 + see below
	355, 356, //Slot 5
	372, //Slot 4 + see above
	357, 358, //Slot 6
	359, 360, 361, 362, //Slot 7
	363, //Slot 8 + see above
	364, //Slot 12
	365, 366, 367, //Slot 9
	368, 369, 371 //Slot 11
};

//GET WEAPON MODEL
/**
 * -DESCRIPTION:
 * 		-Get a weapon's modelid.
 * -PARAMETERS:
 * 		-weaponid: The ID of the weapon to get the modelid of.
 * -RETURN VALUES:
 * 		-valid modelid: The function executed successfully.
 * 		-INVALID_MODEL_ID: The function failed to execute. An invalid weaponid was given.
 */
//native GetWeaponModel(weaponid); //Fake native
stock GetWeaponModel(weaponid) {
	if(weaponid >= 0 && weaponid <= 46) {
		return MainWeapon_WeaponModels[weaponid];
	}
	return INVALID_MODEL_ID;
}

//GET WEAPON VEHICLE DAMAGE
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
//native Float:GetWeaponVehicleDamage(weaponid); //Fake native
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

//========================================HOOKED FUNCTIONS========================================
//GET WEAPON NAME
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
//native GetWeaponName(weaponid, name[], len); //Fake native
stock MainWeapon_GetWeaponName(weaponid, name[], len) {
	if(weaponid >= 0 && weaponid <= 46) {
		return strmid(name, MainWeapon_WeaponNames[weaponid], 0, len, len); //NAMES
	}
	return 0;
}
#if defined _ALS_GetWeaponName
	#undef GetWeaponName
#else
	#define _ALS_GetWeaponName
#endif
#define GetWeaponName MainWeapon_GetWeaponName