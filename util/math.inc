#if defined _mainmath_included
	#endinput
#endif
#define _mainmath_included

// PI
/**
 * -DESCRIPTION:
 * 		-Mathematical constant pi.
 */
#if !defined PI
	#define PI									(Float:3.14159265)
#endif

// INFINITY INTEGER
/**
 * -DESCRIPTION:
 * 		-Largest signed 32-bit integer (2147483647).
 */
#if !defined INFINITY
	#define INFINITY							cellmax
#endif

// NEGATIVE INFINITY INTEGER
/**
 * -DESCRIPTION:
 * 		-Smallest signed 32-bit integer (-2147483648).
 */
#if !defined NEG_INFINITY
	#define NEG_INFINITY						cellmin
#endif

// INFINITY FLOAT
/**
 * -DESCRIPTION:
 * 		-Positive infinity as per the IEEE 754-1985 standard.
 */
#if !defined FLOAT_INFINITY
	#define FLOAT_INFINITY						(Float:0x7F800000)
#endif

// NEGATIVE INFINITY FLOAT
/**
 * -DESCRIPTION:
 * 		-Negative infinity as per the IEEE 754-1985 standard.
 */
#if !defined FLOAT_NEG_INFINITY
	#define FLOAT_NEG_INFINITY					(Float:0xFF800000)
#endif

// NOT A NUMBER FLOAT
/**
 * -DESCRIPTION:
 * 		-Not a number as per the IEEE 754-1985 standard.
 */
#if !defined FLOAT_NAN
	#define FLOAT_NAN							(Float:0x7FFFFFFF)
#endif

// IS NOT A NUMBER
/**
 * -DESCRIPTION:
 * 		-Gets whether a number is not a number.
 * -PARAMETERS:
 * 		-number: The number to check if it is not a number.
 * -RETURN VALUES:
 * 		-true: The function executed successfully. The given number is not a number.
 * 		-false: The function executed successfully. The given number is a number.
 * -NOTES:
 * 		-NaN is a very special number. Comparing it to any other number (including itself) will return false.
 * 		-So number == FLOAT_NAN will not work.
 * -CREDITS:
 * 		-Y_Less: http://forum.sa-mp.com/showthread.php?t=583472
 */
// native bool:IsNaN(number); // Fake native
stock bool:IsNaN(number) {
	return (number != number);
}

// GET POINT ON EDGE OF CIRCLE
/**
 * -DESCRIPTION:
 * 		-Get a point on the edge of a circle given a radius and angle.
 * -PARAMETERS:
 * 		-&Float:x: Before execution the x origin coordinate, after execution the x edge coordinate, passed by reference.
 * 		-&Float:x: Before execution the y origin coordinate, after execution the y edge coordinate, passed by reference.
 * 		-Float:r: The radius.
 * 		-Float:a: The angle.
 * 		-bool:isGTAAngle: Whether the given angle is per the GTA system or per the math system.
 * 		 	-Defaults to false.
 * -RETURN VALUES:
 * 		-This function doesn't return anything.
 * -NOTES:
 * 		-Math angles: N = 90°, E = 0°, S = 270°, W = 180°
 * 		-GTA angles: N = 0°, E = 270°, S = 180°, W = 90°
 */
// native GetPointOnEdgeOfCircle(&Float:x, &Float:y, Float:r, Float:a, bool:isGTAAngle = false); // Fake native
stock GetPointOnEdgeOfCircle(&Float:x, &Float:y, Float:r, Float:a, bool:isGTAAngle = false) {
	if(isGTAAngle) {
		a += 90.0;
	}
	x += r * floatcos(a, degrees);
	y += r * floatsin(a, degrees);
}