#include "lovecalc.h"


// The 'print_usage()' function prints the general info and syntax of the 
// program.

void print_usage (void)
{
	printf("%s",
	"\n"
	"lovecalc - Calculates love percent between different pairs of names\n"
	"\n"
	"SYNOPSIS:\n"
	"   lovecalc [options] [your_name] [his/her_name] \n"
	"\n"
	"OPTIONS:\n"
	"  -v, --verbose   Prints message depending upon result \n"
	"  -h, --help      Prints this help text \n"
	"  -V, --version   Prints version info\n"
	"\n"
	"VERSION:\n"
	"   lovecalc v1.0 \n"
	"\n"
	"AUTHOR:\n"
	"   Manish Munikar (munikarmanish@gmail.com)\n"
	"\n");
}

// The message() function prints the appropriate summary message
// depending upon the love percent.

void message (double result)
{
	if (result > 90.0)
		printf("Made for each other!\n");
	else if (result > 75.0)
		printf("Not bad, eh?\n");
	else if (result > 50.0)
		printf("If you try hard, he/she may be yours.\n");
	else if (result > 30)
		printf("Hard, but definitely not impossible.\n");
	else
		printf("Man, forget it.\n");
}


void print_version(void)
{
	printf("%s",
			" lovecalc v1.0 \n");
}
