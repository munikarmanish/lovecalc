#include "lovecalc.h"

int main (int argc, char **argv)
{
	// Define the long options structure
	//
	// The struct option has the following syntax:
	//
	// struct option {
	// 	char*  long_option_name;
	// 	int    argument_required;
	// 	void*  pointer_to_variable_whose_value_is_changed_by_this_option;
	// 	int    value_to_be_stored_in_3rd_member or equivalent_short_option;
	// };
	
	struct option longOptions[] = {
		{"help", no_argument, 0, 'h'},
		{"verbose", no_argument, &verbose_flag, 1},
		{"version", no_argument, 0, 'V'},
		{0, 0, 0, 0} // ending the list by a null element
	};

	// Parse the options
	
	int c;
	int optionIndex;

	while (1)
	{
		// Look for command line options

		c = getopt_long(argc, argv, "hvV", longOptions, &optionIndex);

		// If searching finishes, break from the loop
		if (c == -1) break;

		// Manipulate the command-line options
		switch (c)
		{
			// 0 is returned by long options.
			// We don't need to do anything here.
			case 0:
				break;

			// If '-v' is specified
			case 'v':
				verbose_flag = 1;
				break;

			case 'V':
				print_version();
				exit(0);

			// If '-h' or '--help' is specified
			case 'h':
				print_usage();
				exit(0);

			// If unknown options are specified
			default:
				fprintf(stderr, "PROGRAMMER ERROR\n");
				exit(-1);
		}
	} // Options parsing is complete

	// Calculate the number of names provided.
	// If it is more than two, print error message.
	
	char name[2][MAXLEN]; // holds two names
	int nNames = 0;       // holds the number of names provided

	// the global variable 'optind' is set as the index of the
	// first non-option argument in the argv array.
	
	while (optind < argc) {
		strcpy(name[nNames], argv[optind]);
		optind++;
		nNames++;
	}

	// If we get more than 3 names, error.
	
	if (nNames > 2) {
		fprintf(stderr, "ERROR: Too many arguments.\n");
		print_usage();
		exit(1);
	}

	// Get incomplete names

	while (nNames < 2) {
		if (nNames == 0)      printf("Enter your name:    ");
		else if (nNames == 1) printf("Enter his/her name: ");
		
		// Get valid name

		int valid = 0;
		while (!valid) {
			getstr(name[nNames], MAXLEN, stdin);
			
			// If first letter of provided name is not alphabet, ask again.

			if (!isalpha(name[nNames][0])) {
				printf("Invalid name.\nEnter a valid name: ");
			}
			else {
				valid = 1;
			}
		}

		nNames++;
	}

	// Calculate

	printf("Result = %.2f%\n", lovecalc(name));

	// If verbose_flag is set, then print the message

	if (verbose_flag)
		message(lovecalc(name));

	return (EXIT_SUCCESS);
}
