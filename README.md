# samp-util
[![sampctl](https://img.shields.io/badge/sampctl-samp--util-2f2f2f.svg?style=for-the-badge)](https://github.com/WoutProvost/samp-util)

A set of useful functions for SA-MP.

## Installation
Simply install to your project:
```bash
sampctl package install WoutProvost/samp-util
```

Include in your code and begin using the library:
```pawn
#include <util>
```

## Usage
Detailed documentation is provided in the include files.
### Color.inc
```pawn
#define COLOR_SP_MAPICON_ENEMY				0xb31a1eff
#define COLOR_SP_MAPICON_ALLY				0x343d7eff
#define COLOR_SP_MAPICON_OBJECTIVE			0xe2c063ff
#define COLOR_SP_GAMETEXT_RED				0x9c1634ff
#define COLOR_SP_GAMETEXT_BLUE				0x2b346eff
#define COLOR_SP_GAMETEXT_YELLOW			0xc4a656ff
#define COLOR_SP_HEALTH_FG				0xb4191dff
#define COLOR_SP_HEALTH_BG				0x5a0c0eff
#define COLOR_SP_ARMOUR_FG				0xe1e1e1ff
#define COLOR_SP_ARMOUR_BG				0x707070ff
#define COLOR_SP_BREATH_FG				0xaccbf1ff
#define COLOR_SP_BREATH_BG				0x566578ff
#define COLOR_SP_MONEY					0x2f5a26ff
#define COLOR_SP_CLOCK					0xc3c3c3ff
#define COLOR_DIALOG_INFO_NORMAL			0xa9c4e4ff
#define COLOR_LOG					0xa9c4e4ff
```
### Math.inc
```pawn
#define PI						(Float:3.14159265)
#define INFINITY					cellmax // = 2147483647
#define NEG_INFINITY					cellmin // = -2147483648
#define FLOAT_INFINITY					(Float:0x7F800000)
#define FLOAT_NEG_INFINITY				(Float:0xFF800000)
#define FLOAT_NAN					(Float:0x7FFFFFFF)

bool:IsNaN(number);
GetPointOnEdgeOfCircle(&Float:x, &Float:y, Float:r, Float:a, bool:isGTAAngle = false);
```
### String.inc
```pawn
#define MAX_TEXT_INPUT					128
#define MAX_TEXT_OUTPUT					144

strtok(const string[], &index, delimiter = ' ');
strrest(const string[], &index, delimiter = ' ');
strcpy(dest[], const source[], len = sizeof(dest));
strclr(string[]);
bool:strempty(const string[]);
strcount(const string[], character);
strtolower(string[]);
strtoupper(string[]);
GetCharacterWidth(c);
GetStringWidth(const string[]);
AddThousandsSeparators(number, separator = ',');
TrimTrailingZeros(string[], keep = 0);
ReplaceDecimalSeparator(Float:number, separator = ',', precision = 6);
FormatFloat(Float:number, keep = 0, precision = 6, decimalSeparator = '.', thouasandsSeparator = ',');
```
### Calendar.inc
```pawn
#define MAX_WEEKDAY_NAME				9
#define MAX_WEEKDAY_SHORT_NAME				3
#define MAX_MONTH_NAME					9
#define MAX_MONTH_SHORT_NAME				3

GetWeekDay(year, month, day);
GetWeekdayName(weekday, name[], len);
GetWeekdayShortName(weekday, name[], len);
GetMonthName(month, name[], len);
GetMonthShortName(month, name[], len);
```
### Invalid.inc
```pawn
#define INVALID_SKIN_ID					-1
#define INVALID_MODEL_ID				-1
#define INVALID_CHECKPOINT_ID				-1
#define INVALID_MAPICON_ID				-1
#define INVALID_PICKUP_ID				-1
#define INVALID_AREA_ID					-1
#define INVALID_TIMER_ID				-1
```
### Limit.inc
```pawn
#define MAX_CHECKPOINTS					1
#define MAX_RACE_CHECKPOINTS				1
#define MAX_MAPICONS					100
#define MAX_OBJECT_MATERIAL_TEXT			2048
#define MAX_PLAYER_VARIABLES				800
#define MAX_GAMEMODES					16
#define MAX_FILTERSCRIPTS				16
```
### Textdraw.inc
```pawn
#define MAX_TEXT_DRAW_TEXT				1024
#define MAX_TEXT_DRAWS_SHOWN				MAX_TEXT_DRAWS+MAX_PLAYER_TEXT_DRAWS
#define MAX_TEXT_DRAW_SPRITES_SHOWN			100
```
### Dialog.inc
```pawn
#define MAX_DIALOGS					32768
#define MAX_DIALOG_CAPTION				64
#define MAX_DIALOG_INFO					4096
#define MAX_DIALOG_BUTTON_TEXT				10
#define MAX_DIALOG_INPUT				128
#define MAX_DIALOG_COLUMNS				4
#define MAX_DIALOG_COLUMN_NAME				128
#define MAX_DIALOG_ROW_TEXT				256
```
### Virtualworld.inc
```pawn
#define MAX_VIRTUAL_WORLDS				cellmax // = 2147483647
#define INVALID_VIRTUAL_WORLD_ID			-1
#define VIRTUAL_WORLD_NORMAL				0
```
### Interior.inc
```pawn
#define MAX_INTERIORS					256
#define INVALID_INTERIOR_ID				-1
#define INTERIOR_NORMAL					0
```
### Weather.inc
```pawn
#define WEATHER_NORMAL					10

GetWeather();
```
### Time.inc
```pawn
#define TIME_HOUR_NORMAL				12
#define TIME_MINUTE_NORMAL				0

GetWorldTime();
```
### Class.inc
```pawn
#define INVALID_CLASS_ID				-1
#define MAX_CLASSES					320

AddPlayerClassEx(teamid, modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1 = 0, weapon1_ammo = 0, weapon2 = 0, weapon2_ammo = 0, weapon3 = 0, weapon3_ammo = 0, worldid = VIRTUAL_WORLD_NORMAL, interiorid = INTERIOR_NORMAL);
AddPlayerClass(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, weapon1 = 0, weapon1_ammo = 0, weapon2 = 0, weapon2_ammo = 0, weapon3 = 0, weapon3_ammo = 0, teamid = NO_TEAM, worldid = VIRTUAL_WORLD_NORMAL, interiorid = INTERIOR_NORMAL);

// Makes sure that the player respawns in the world belonging to the class.
// Makes sure that the player respawns in the interior belonging to the class.
```
### Vehicle.inc
```pawn
#define MAX_VEHICLE_MODELS				212
#define INVALID_PAINTJOB_ID				-1
#define PAINTJOB_NONE					3
#define INVALID_VEHICLE_COLOR_ID			-2
#define MAX_VEHICLE_MODEL_NAME				21
#define INVALID_VEHICLE_TYPE				-1
enum {
	VEHICLE_TYPE_CAR,
	VEHICLE_TYPE_TRACTOR,
	VEHICLE_TYPE_BIKE,
	VEHICLE_TYPE_BICYCLE,
	VEHICLE_TYPE_QUAD,
	VEHICLE_TYPE_HOVERCRAFT,
	VEHICLE_TYPE_RC,
	VEHICLE_TYPE_BOAT,
	VEHICLE_TYPE_HELI,
	VEHICLE_TYPE_SEAHELI,
	VEHICLE_TYPE_PLANE,
	VEHICLE_TYPE_SEAPLANE,
	VEHICLE_TYPE_TRAIN,
	VEHICLE_TYPE_TRAILER
}

bool:IsValidVehicle(vehicleid);
bool:IsVehicleInNormalWorld(vehicleid);
GetVehicleInterior(vehicleid);
SetVehicleInterior(vehicleid, interiorid);
SetVehiclePaintjob(vehicleid, paintjobid);
ChangeVehicleColor(vehicleid, color1, color2);
ChangeVehicleColors(vehicleid, color1, color2);
ChangeVehicleColour(vehicleid, color1, color2);
ChangeVehicleColours(vehicleid, color1, color2);
SetVehicleColor(vehicleid, color1, color2);
SetVehicleColors(vehicleid, color1, color2);
SetVehicleColour(vehicleid, color1, color2);
SetVehicleColours(vehicleid, color1, color2);
GetVehicleModelName(modelid, name[], len);
GetVehicleModelSeatCount(modelid);
GetVehicleModelType(modelid);
GetVehicleDriver(vehicleid);
bool:IsVehicleUpsideDown(vehicleid);
CreateVehicle(vehicletype, Float:x, Float:y, Float:z, Float:rotation, color1 = -1, color2 = -1, respawn_delay = 0, addsiren = false, worldid = VIRTUAL_WORLD_NORMAL, interiorid = INTERIOR_NORMAL, paintjobid = PAINTJOB_NONE);
AddStaticVehicleEx(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1 = -1, color2 = -1, respawn_delay = 0, addsiren = false, worldid = VIRTUAL_WORLD_NORMAL, interiorid = INTERIOR_NORMAL, paintjobid = PAINTJOB_NONE);
AddStaticVehicle(modelid, Float:spawn_x, Float:spawn_y, Float:spawn_z, Float:z_angle, color1 = -1, color2 = -1, respawn_delay = 0, addsiren = false, worldid = VIRTUAL_WORLD_NORMAL, interiorid = INTERIOR_NORMAL, paintjobid = PAINTJOB_NONE);
DestroyVehicle(vehicleid);

forward OnVehicleVirtualWorldChange(vehicleid, newvirtualworldid, oldvirtualworldid);
forward OnVehicleInteriorChange(vehicleid, newinteriorid, oldinteriorid);

// Makes sure that trains are always created with AddStaticVehicleEx and not wrongly with CreateVehicle. Trains can only be added with AddStaticVehicle and AddStaticVehicleEx.
// Makes sure that the vehicle respawns in the world it was first created.
// Makes sure that the vehicle respawns in the interior it was first created.
// Makes sure that the vehicle respawns with the paintjob it was given when it was first created.
// Syncs random vehicle colours between players.
```
### Player.inc
```pawn
ClearChat(playerid);
ClearKillFeed(playerid);
ClearGameTexts(playerid);
ReturnPlayerNameAndID(playerid);
PlaySoundForPlayersInRange(soundid, Float:x, Float:y, Float:z, Float:range = 50.0, worldid = VIRTUAL_WORLD_NORMAL, interiorid = INTERIOR_NORMAL);
bool:IsPlayerInNormalWorld(playerid);
SetPlayerPos(playerid, Float:x, Float:y, Float:z, bool:preload = false);

forward OnPlayerVirtualWorldChange(playerid, newvirtualworldid, oldvirtualworldid);
```
### Weapon.inc
```pawn
#define INVALID_WEAPON_ID				-1
#define MAX_WEAPON_NAME					31

GetWeaponModel(weaponid);
Float:GetWeaponVehicleDamage(weaponid);
bool:IsMeleeWeapon(weaponid);
GetWeaponName(weaponid, name[], len);
```
### Audiostream.inc
```pawn
PlayAudioStream(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, usepos = 0, time = -1);
StopAudioStream(playerid);
```
### Zone.inc
```pawn
#define MAX_ZONES					366
#define MAX_ZONE_NAME					26

GetZoneID(Float:x, Float:y, Float:z);
GetZoneName(zoneid, name[], len);
GetZoneCoordinates(zoneid, &Float:x_min, &Float:y_min, &Float:z_min, &Float:x_max, &Float:y_max, &Float:z_max);
```
### Custom/Interior.inc
```pawn
#define INTERIOR_LIBERTY_CITY				1
```
### Custom/Vehicle.inc
```pawn
#define PAINTJOB_MOTHERSHIP				0
```

## Testing
To test, simply run the package:
```bash
sampctl package run
```
