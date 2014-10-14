#include "lovecalc.h"

double lovecalc(char name[2][MAXLEN])
{
	int len[2];

	// Convert all letters into UPPERCASE
	
	int i, j;
	for (i = 0; i < 2; i++) {
		len[i] = strlen(name[i]);
		for (j = 0; j < strlen(name[i]); j++) {
			name[i][j] = toupper(name[i][j]);
		}
	}

	// Then sum up the ASCII values of all the characters in both names

	double sum = 0;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < strlen(name[i]); j++) {
			sum += (double) name[i][j];
		}
	}

	// Then play with the sum to obtain a pseudo-random number.
	//
	// We haven't used the rand() function because we want to return the
	// same result for the same pair every time.

	sum *= 12345.6789;
	sum = (double) ((int) sum % 10000);
	sum = (sum / 10000.0) * 50.0;
	
	return (sum * 2.0);
}
