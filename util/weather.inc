#if defined _mainweather_included
	#endinput
#endif
#define _mainweather_included

// DEFAULT WEATHER
/**
 * -DESCRIPTION:
 * 		-Defines the default weather used by SA-MP.
 * -NOTES:
 * 		-Uses the '_NORMAL' naming scheme instead of the '_DEFAULT' naming scheme, to be in line with the naming scheme used by SA-MP for e.g. fighting styles.
 */
#define WEATHER_NORMAL						10

// GET WEATHER
/**
 * -DESCRIPTION:
 * 		-Get the weather.
 * -PARAMETERS:
 * 		-This function has no parameters.
 * -RETURN VALUES:
 * 		-weather: The function executed successfully.
 */
// native GetWeather(); // Fake native
#if !defined GetWeather
	stock GetWeather() {
		return GetConsoleVarAsInt("weather");
	}
#endif