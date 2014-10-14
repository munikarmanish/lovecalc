#include "lovecalc.h"

// The 'getstr()' function is a modified version of fgets() function.
//
// The fgets() also consumes the Enter (\n) character pressed by user.
// This function will return the string with the last '\n' character
// deleted.

char *getstr (char *string, int size, FILE* file)
{
	fgets(string, size, file);

	int len = strlen(string);

	if (string[len-1] == '\n')
		string[len-1] = 0;

	return string;
}
