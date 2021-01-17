#if defined _maincalendar_included
	#endinput
#endif
#define _maincalendar_included

// GET WEEK DAY
/**
 * -DESCRIPTION:
 * 		-Get the day of the week of a given date.
 * -PARAMETERS:
 * 		-year: The year of the date to get the weekday of.
 * 		-month: The month of the date to get the weekday of.
 * 		-day: The day of the date to get the weekday of.
 * -RETURN VALUES:
 * 		-valid weekday: The function executed successfully.
 * -NOTES:
 * 		-Sunday = 0, Monday = 1, etc.
 * 		-This function preserves neither year nor day, but this is not an issue since the parameters are passed by value.
 * -CREDITS:
 * 		-Michael Keith and Tom Craver: https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Implementation-dependent_methods
 */
// native GetWeekDay(year, month, day); // Fake native
stock GetWeekDay(year, month, day) {
	return (day += month < 3 ? year-- : year-2 , 23*month/9+day+4+year/4-year/100+year/400) % 7;
}

// WEEKDAY NAMES
/**
 * -DESCRIPTION:
 * 		-Weekday names and 3 character abbreviations.
 */
#define MAX_WEEKDAY_NAME					9
#define MAX_WEEKDAY_SHORT_NAME				3
static const MainCalendar_WeekdayNames[][2][] = {
	{"Sunday", "Sun"},
	{"Monday", "Mon"},
	{"Tuesday", "Tue"},
	{"Wednesday", "Wed"},
	{"Thursday", "Thu"},
	{"Friday", "Fri"},
	{"Saturday", "Sat"}
};

// GET WEEKDAY NAME
/**
 * -DESCRIPTION:
 * 		-Get a weekday's name.
 * -PARAMETERS:
 * 		-weekday: The weekday to get the name of.
 * 		-name[]: An array into which to store the name, passed by reference.
 * 		-len: The length of the string that should be stored. Recommended to be MAX_WEEKDAY_NAME + 1.
 * -RETURN VALUES:
 * 		-name length: The function executed successfully.
 * 		-0: The function failed to execute. An invalid weekday was given.
 * -NOTES:
 * 		-Works like GetPlayerName so that the name is stored in the given string parameter.
 */
// native GetWeekdayName(weekday, name[], len); // Fake native
stock GetWeekdayName(weekday, name[], len) {
	if(weekday >= 0 && weekday <= 6) {
		// WEEKDAY NAMES
		return strmid(name, MainCalendar_WeekdayNames[weekday][0], 0, len, len);
	}
	return 0;
}

// GET WEEKDAY SHORT NAME
/**
 * -DESCRIPTION:
 * 		-Get a weekday's abbreviated name.
 * -PARAMETERS:
 * 		-weekday: The weekday to get the abbreviated name of.
 * 		-name[]: An array into which to store the abbreviated name, passed by reference.
 * 		-len: The length of the string that should be stored. Recommended to be MAX_WEEKDAY_SHORT_NAME + 1.
 * -RETURN VALUES:
 * 		-abbreviated name length: The function executed successfully.
 * 		-0: The function failed to execute. An invalid weekday was given.
 * -NOTES:
 * 		-Works like GetPlayerName so that the abbreviated name is stored in the given string parameter.
 */
// native GetWeekdayShortName(weekday, name[], len); // Fake native
stock GetWeekdayShortName(weekday, name[], len) {
	if(weekday >= 0 && weekday <= 6) {
		// WEEKDAY NAMES
		return strmid(name, MainCalendar_WeekdayNames[weekday][1], 0, len, len);
	}
	return 0;
}

// MONTH NAMES
/**
 * -DESCRIPTION:
 * 		-Month names and 3 character abbreviations.
 */
#define MAX_MONTH_NAME						9
#define MAX_MONTH_SHORT_NAME				3
static const MainCalendar_MonthNames[][2][] = {
	{"January", "Jan"},
	{"February", "Feb"},
	{"March", "Mar"},
	{"April", "Apr"},
	{"May", "May"},
	{"June", "Jun"},
	{"July", "Jul"},
	{"August", "Aug"},
	{"September", "Sep"},
	{"October", "Oct"},
	{"November", "Nov"},
	{"December", "Dec"}
};

// GET MONTH NAME
/**
 * -DESCRIPTION:
 * 		-Get a month's name.
 * -PARAMETERS:
 * 		-month: The month to get the name of.
 * 		-name[]: An array into which to store the name, passed by reference.
 * 		-len: The length of the string that should be stored. Recommended to be MAX_MONTH_NAME + 1.
 * -RETURN VALUES:
 * 		-name length: The function executed successfully.
 * 		-0: The function failed to execute. An invalid month was given.
 * -NOTES:
 * 		-Works like GetPlayerName so that the name is stored in the given string parameter.
 */
// native GetMonthName(month, name[], len); // Fake native
stock GetMonthName(month, name[], len) {
	if(month >= 1 && month <= 12) {
		// MONTH NAMES
		return strmid(name, MainCalendar_MonthNames[month-1][0], 0, len, len);
	}
	return 0;
}

// GET MONTH SHORT NAME
/**
 * -DESCRIPTION:
 * 		-Get a month's abbreviated name.
 * -PARAMETERS:
 * 		-month: The month to get the abbreviated name of.
 * 		-name[]: An array into which to store the abbreviated name, passed by reference.
 * 		-len: The length of the string that should be stored. Recommended to be MAX_MONTH_SHORT_NAME + 1.
 * -RETURN VALUES:
 * 		-abbreviated name length: The function executed successfully.
 * 		-0: The function failed to execute. An invalid month was given.
 * -NOTES:
 * 		-Works like GetPlayerName so that the abbreviated name is stored in the given string parameter.
 */
// native GetMonthShortName(month, name[], len); // Fake native
stock GetMonthShortName(month, name[], len) {
	if(month >= 1 && month <= 12) {
		// MONTH NAMES
		return strmid(name, MainCalendar_MonthNames[month-1][1], 0, len, len);
	}
	return 0;
}