#if defined _mainstring_included
	#endinput
#endif
#define _mainstring_included

// TEXT INPUT LIMIT
/**
 * -DESCRIPTION:
 * 		-Defines the text input limit.
 */
#define MAX_TEXT_INPUT						128

// TEXT OUTPUT LIMIT
/**
 * -DESCRIPTION:
 * 		-Defines the text output limit.
 */
#define MAX_TEXT_OUTPUT						144

// STRING TOKENIZE
/**
 * -DESCRIPTION:
 * 		-Splits/tokenizes a string into parts with a given delimiter and gets the next token after the given character index.
 * -PARAMETERS:
 * 		-const string[]: The string to split into parts, passed by reference.
 * 		-&index: The character index, passed by reference.
 * 		-delimiter: The character with which to split the string.
 * 		 	-Defaults to ' ', which is a space.
 * -RETURN VALUES:
 * 		-token: The function executed successfully.
 * -CREDITS:
 * 		-samp_svr/include/gl_common.inc
 * 		-Delimiter parameter added by Freaksken.
 */
// native strtok(const string[], &index, delimiter = ' '); // Fake native
stock strtok(const string[], &index, delimiter = ' ') {
	new length = strlen(string);
	while ((index < length) && (string[index] <= delimiter)) {
		index++;
	}
	new offset = index;
	new result[128];
	while ((index < length) && (string[index] > delimiter) && ((index - offset) < (sizeof(result) - 1))) {
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

// STRING REST
/**
 * -DESCRIPTION:
 * 		-Splits/tokenizes a string into parts with a given delimiter and gets the rest of the string after the given character index.
 * -PARAMETERS:
 * 		-const string[]: The string to split into parts, passed by reference.
 * 		-&index: The character index, passed by reference.
 * 		-delimiter: The character with which to split the string.
 * 		 	-Defaults to ' ', which is a space.
 * -RETURN VALUES:
 * 		-rest of the string: The function executed successfully.
 * -CREDITS:
 * 		-samp_svr/include/gl_common.inc
 * 		-Delimiter parameter added by Freaksken.
 */
// native strrest(const string[], &index, delimiter = ' '); // Fake native
stock strrest(const string[], &index, delimiter = ' ') {
	new length = strlen(string);
	while ((index < length) && (string[index] <= delimiter)) {
		index++;
	}
	new offset = index;
	new result[128];
	while ((index < length) && ((index - offset) < (sizeof(result) - 1))) {
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

// STRING COPY
/**
 * -DESCRIPTION:
 * 		-Copies the source string to the destination string.
 * -PARAMETERS:
 * 		-dest[]: The destination string to copy the source string to, passed by reference.
 * 		-const source[]: The source string to copy to the destination string, passed by reference.
 * 		-len: The maximum length of the destination string.
 * -RETURN VALUES:
 * 		-length of the new destination string: The function executed successfully.
 * -CREDITS:
 * 		-Y_Less: http://forum.sa-mp.com/showpost.php?p=94960&postcount=2
 * 		-Converted from preprocessor constant to function by Freaksken.
 */
// native strcpy(dest[], const source[], len = sizeof(dest)); // Fake native
stock strcpy(dest[], const source[], len = sizeof(dest)) {
	dest[0] = '\0';
	return strcat(dest, source, len);
}

// STRING CLEAR
/**
 * -DESCRIPTION:
 * 		-Clears/empties the string.
 * -PARAMETERS:
 * 		-string[]: The string to clear, passed by reference.
 * -RETURN VALUES:
 * 		-This function doesn't return anything.
 */
// native strclr(string[]); // Fake native
stock strclr(string[]) {
	string[0] = '\0';
}

// STRING IS EMPTY
/**
 * -DESCRIPTION:
 * 		-Get whether a string is empty.
 * -PARAMETERS:
 * 		-const string[]: The string to get whether it is empty, passed by reference.
 * -RETURN VALUES:
 * 		-true: The function executed successfully. The string is empty.
 * 		-false: The function executed successfully. The string is not empty.
 * -NOTES:
 * 		-Due to the way the PAWN VM works, strings passed by CallRemoteFunction and CallLocalFunction MUST NOT have 0 length, so empty strings are passed as "\1\0" (i.e. character 1 (SOH), character 0 (NULL)).
 * -CREDITS:
 * 		-Y_Less: http://forum.sa-mp.com/showpost.php?p=94960&postcount=2
 * 		-Converted from preprocessor constant to function and name changed by Freaksken, originally called isnull.
 */
// native bool:strempty(const string[]); // Fake native
stock bool:strempty(const string[]) {
	if(string[0] == '\0' || (string[0] == '\1' && string[1] == '\0')) {
		return true;
	}
	return false;
}

// STRING COUNT
/**
 * -DESCRIPTION:
 * 		-Counts the amount of occurrences the character has in the string.
 * -PARAMETERS:
 * 		-const string[]: The string to count the amount of occurrences the character has in, passed by reference.
 * 		-character: The character to count the amount of occurrences of.
 * -RETURN VALUES:
 * 		-amount: The function executed successfully. The character has this many occurrences.
 */
// native strcount(const string[], character); // Fake native
stock strcount(const string[], character) {
	new count = 0;
	for(new c = 0, length = strlen(string); c < length; c++) {
		if(string[c] == character) {
			count++;
		}
	}
	return count;

	/*
	new count = 0, c = 0;
	while(string[c] != '\0') {
		if(string[c] == character) {
			count++;
		}
		c++;
	}
	return count;*/
}

// STRING TO LOWER
/**
 * -DESCRIPTION:
 * 		-Changes all characters in the string to lowercase.
 * -PARAMETERS:
 * 		-string[]: The string to change all characters to lowercase of, passed by reference.
 * -RETURN VALUES:
 * 		-This function doesn't return anything.
 */
// native strtolower(string[]); // Fake native
stock strtolower(string[]) {
	for(new c = 0, length = strlen(string); c < length; c++) {
		string[c] = tolower(string[c]);
	}

	/*new c = 0;
	while(string[c] != '\0') {
		string[c] = tolower(string[c]);
		c++;
	}*/
}

// STRING TO UPPER
/**
 * -DESCRIPTION:
 * 		-Changes all characters in the string to uppercase.
 * -PARAMETERS:
 * 		-string[]: The string to change all characters to uppercase of, passed by reference.
 * -RETURN VALUES:
 * 		-This function doesn't return anything.
 */
// native strtoupper(string[]); // Fake native
stock strtoupper(string[]) {
	for(new c = 0, length = strlen(string); c < length; c++) {
		string[c] = toupper(string[c]);
	}

	/*new c = 0;
	while(string[c] != '\0') {
		string[c] = toupper(string[c]);
		c++;
	}*/
}

// TEXTDRAW CHARACTER WIDTHS
/**
 * -DESCRIPTION:
 * 		-Proportional values for textdraw font ID 1.
 * -NOTES:
 * 		-These values are only correct when (Player)TextDrawSetProportional is set to 1.
 * 		-The final values depend on TextDrawLetterSize and TextDrawSetOutline. There is no easy way to calculate to additional 'thickness', since the outline of one character can, but will not always, flow over to the outline of the next.
 * 		-The returned widths should be multiplied by the texdraw letter size.
 * -CREDITS:
 * 		-GTA San Andreas/data/fonts.dat
 */
static const MainString_CharacterWidths[] = { // Data taken from singleplayer fonts.dat file
	 0, 15, 15, 15, 15, 15, 15, 15,	// NULL is not displayable because it breaks off the string, others display as a space
	15, 15, 15, 15, 15, 15, 15, 15,	// Display as a space
	15, 15, 15, 15, 15, 15, 15, 15,	// Display as a space
	15, 15, 15, 15, 15, 15, 15, 15,	// Display as a space
	15,  9, 17, 27, 20, 34, 23, 12,	//   ! " £ $ % & '
	12, 12, 21, 20, 12, 14, 12, 15,	// ( ) * + , - . /
	23, 15, 21, 21, 21, 21, 21, 21,	// 0 1 2 3 4 5 6 7
	20, 21, 12, 12, 24, 24, 24, 19,	// 8 9 : ; < = > ?
	10, 22, 19, 19, 22, 16, 19, 24,	// tmA B C D E F G
	22, 11, 16, 21, 15, 28, 24, 27,	// H I J K L M N O
	20, 25, 19, 19, 18, 23, 23, 31,	// P Q R S T U V W
	23, 19, 21, 21, 13, 35, 11, 21,	// X Y Z       ! _
	10, 19, 20, 14, 20, 19, 13, 20,	// ! a b c d e f g
	19,  9,  9, 19,  9, 29, 19, 21,	// h i j k l m n o
	19, 19, 15, 15, 14, 18, 19, 27,	// p q r s t u v w
	20, 20, 17, 21, 17, 20, 15, 15,	// x y z     $ [ ]
	22, 22, 22, 22, 29, 19, 16, 16,	// À Á Â Ã Æ Ç È É
	16, 16, 11, 11, 11, 11, 27, 27,	// Ê Ë Ì Í Î Ï Ò Ó
	27, 27, 23, 23, 23, 23, 20, 19,	// Ô Ö Ù Ú Û Ü ß à
	19, 19, 19, 30, 14, 19, 19, 19,	// á â ã æ ç è é ê
	19,  9,  9,  9,  9, 21, 21, 21,	// ë ì í î ï ò ó ô
	21, 18, 18, 18, 18, 24, 19, 19,	// ö ù ú û ü Ñ ñ ¿
	20, 18, 19, 19, 21, 19, 19, 19,	// 0 1 2 3 4 5 6 7
	19, 19, 16, 19, 19, 19, 20, 19,	// 8 9 : A B C D E
	16, 19, 19,  9, 19, 20, 14, 29,	// F G H I J K L M
	19, 19, 19, 19, 19, 19, 21, 19,	// N O P Q R S T U
	20, 32, 21, 19, 19, 19, 19, 19,	// V W X Y Z À Á Â
	19, 29, 19, 19, 19, 19, 19,  9,	// Ã Æ Ç È É Ê Ë Ì
	 9,  9,  9, 19, 19, 19, 19, 19,	// Í Î Ï Ò Ó Ô Ö Ù
	19, 19, 19, 19, 21, 19, 10,  9	// Ú Û Ü ß Ñ ¿ ' .
};

// GET TEXTDRAW CHARACTER WIDTH
/**
 * -DESCRIPTION:
 * 		-Get the proportional textdraw width of a character.
 * -PARAMETERS:
 * 		-c: The character to get the proportional width of.
 * -RETURN VALUES:
 * 		-actual character width: The function executed successfully. The character exists.
 * 		-default character width: The function executed successfully. The character doesn't exist.
 */
// native GetCharacterWidth(c); // Fake native
stock GetCharacterWidth(c) {
	if(c < 0) {
		return 0;
	}
	if(c >= sizeof(MainString_CharacterWidths)) {
		return 20; // Default width, also taken from singleplayer fonts.dat file
	}
	return MainString_CharacterWidths[c];
}

// GET TEXTDRAW STRING WIDTH
/**
 * -DESCRIPTION:
 * 		-Get the proportional textdraw width of a string.
 * -PARAMETERS:
 * 		-const string[]: The string to get the proportional width of, passed by reference.
 * -RETURN VALUES:
 * 		-combined character width: The function executed successfully.
 */
// native GetStringWidth(const string[]); // Fake native
stock GetStringWidth(const string[]) {
	new width = 0;
	for(new c = 0, length = strlen(string); c < length; c++) {
		width += GetCharacterWidth(string[c]);
	}
	return width;

	/*
	new width = 0, c = 0;
	while(string[c] != '\0') {
		width += GetCharacterWidth(string[c]);
		c++;
	}
	return width;*/
}

// ADD THOUSANDS SEPARATOR
/**
 * -DESCRIPTION:
 * 		-Add a thousands separator between groups of 3 digits of an integer.
 * -PARAMETERS:
 * 		-number: The integer to add the thousands separators to.
 * 		-separator: The separator to insert between groups of 3 digits.
 * 		 	-Defaults to ','.
 * -RETURN VALUES:
 * 		-string with formatted number: The function executed successfully.
 * -CREDITS:
 * 		-Vince: http://wiki.sa-mp.com/wiki/AddThousandsSeparators#Definition
 * 		-Separator as character instead of string by Freaksken.
 */
// native AddThousandsSeparators(number, separator = ','); // Fake native
stock AddThousandsSeparators(number, separator = ',') {
	new output[14 + 1]; // The longest possible output for 32 bit integers is -2,147,483,648 and thus 14 characters
	new separatorString[1 + 1];
	format(output, sizeof(output), "%d", number);
	format(separatorString, sizeof(separatorString), "%c", separator);
	for(new i = strlen(output) - 3; i > 0 && output[i-1] != '-'; i -= 3) {
		strins(output, separatorString, i);
	}
	return output;
}

// TRIM TRAILING ZEROS
/**
 * -DESCRIPTION:
 * 		-Trim trailing zeros of a string.
 * -PARAMETERS:
 * 		-string[]: The string to trim the trailing zeros of, passed by reference.
 * 		-keep: The amount of zeros to keep, if there are that many.
 * 		 	-Defaults to 0.
 * -RETURN VALUES:
 * 		-This function doesn't return anything.
 */
// native TrimTrailingZeros(string[], keep = 0); // Fake native
stock TrimTrailingZeros(string[], keep = 0) {
	new length = strlen(string);
	new i = length - 1;
	while(i > 0 && string[i] == '0') {
		i--;
	}
	new keepmax = length - i - 1;
	if(keep > keepmax) {
		keep = keepmax;
	}
	string[i + keep + 1] = '\0';

	// 16.123	keep 0	==> 16.123
	// 16.123000	keep 1	==> 16.1230
	// 16.123000	keep 4	==> 16.123000
	// 16.123	keep 1	==> 16.123
}

// REPLACE DECIMAL SEPARATOR
/**
 * -DESCRIPTION:
 * 		-Replaces the decimal separator of a float.
 * -PARAMETERS:
 * 		-Float:number: The float to replace the decimal separator of.
 * 		-separator: The separator to replace the decimal separator with.
 * 		 	-Defaults to ','.
 * 		-precision: The precision of the float to use during conversion to a string.
 * 		 	-Defaults to 6.
 * -RETURN VALUES:
 * 		-string with formatted number: The function executed successfully.
 * -NOTES:
 * 		-The implicit precision of a float given to the format/printf function is 6, which is the maximum number of decimals that can be converted to a string and back, without a change of precision.
 * 		-A precision of more than 6 will result in faulty conversions: printf("%.20f", 3.14159265358979323846); gives 3.14159274101257324218.
 */
// native ReplaceDecimalSeparator(Float:number, separator = ',', precision = 6); // Fake native
stock ReplaceDecimalSeparator(Float:number, separator = ',', precision = 6) {
	new output[64 + 1]; // Both printf and format have an internal buffer of 64 characters for floats, for both whole and fractional parts combined
	new separatorString[1 + 1];
	format(output, sizeof(output), "%.*f", precision, number);
	format(separatorString, sizeof(separatorString), "%c", separator);
	new pos = strfind(output, ".");
	if(pos != -1) {
		strdel(output, pos, pos + 1);
		strins(output, separatorString, pos);
	}
	return output;
}

// FORMAT FLOAT
/**
 * -DESCRIPTION:
 * 		-Returns a string with a formatted float.
 * -PARAMETERS:
 * 		-Float:number: The number to format.
 * 		-keep: The amount of zeros to keep, if there are that many.
 * 		 	-Defaults to 0.
 * 		-precision: The precision of the float to use during conversion to a string.
 * 		 	-Defaults to 6.
 * 		-decimalSeparator: The separator to replace the decimal separator with.
 * 		 	-Defaults to '.'.
 * 		-thouasandsSeparator: The separator to insert between groups of 3 digits.
 * 		 	-Defaults to ','.
 * -RETURN VALUES:
 * 		-string with formatted float: The function executed successfully.
 * -NOTES:
 * 		-See ReplaceDecimalSeparator for more information on the precision.
 */
// native FormatFloat(Float:number, keep = 0, precision = 6, decimalSeparator = '.', thouasandsSeparator = ','); // Fake native
stock FormatFloat(Float:number, keep = 0, precision = 6, decimalSeparator = '.', thouasandsSeparator = ',') {
	// Replace the decimal separator
	new output[64 + 3 + 1]; // See ReplaceDecimalSeparator for more information on this number
	output = ReplaceDecimalSeparator(number, decimalSeparator, precision);

	// Trim trailing zeros
	TrimTrailingZeros(output, keep);

	// Remove the decimal separator when there are no decimals left
	new length = strlen(output);
	if(output[length - 1] == decimalSeparator) {
		output[length - 1] = '\0';
	}

	// Add thousands separators to the whole/integer part of the float
	new front[MAX_TEXT_INPUT + 1], end[MAX_TEXT_INPUT + 1], idx;
	front = strtok(output, idx, decimalSeparator);
	end = strtok(output, idx, decimalSeparator);
	new frontval = strval(front);
	output = AddThousandsSeparators(number < 0 ? frontval*-1 : frontval, thouasandsSeparator);
	if(strlen(end) > 0) {
		new separatorString[1 + 1];
		format(separatorString, sizeof(separatorString), "%c", decimalSeparator);
		strcat(output, separatorString);
		strcat(output, end);
	}
	return output;
}