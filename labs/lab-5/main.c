#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

int main() {
	
	int n_apts = 5;
	APT * apts = (APT *)malloc(n_apts * sizeof(APT)); // allocates memory for list
	APT * p_apt;

	int start = 0, counter = 0; // variables to track the circular list
	bool is_quit = false;

	while (is_quit == false) {

		char command;
		printf("Choose a command:\na - add an appointment\np - print list of appointments\nn - next appointment\nq - quit program\n\n");

		scanf("%c", &command);
		switch (command) {
			case 'a':
				printf("Input data for an appointment: <name> ");
				fgets((p_apt->name), sizeof(p_apt->name), stdin);
				printf("\nInput data for an appointment: <location> ");
				fgets(p_apt->loc, sizeof(p_apt->loc), stdin);
				printf("Input data for an appointment: <duration> ");
				scanf(" %d", &p_apt->dur);
				printf("Input date and time for appointment: <day> <month> <year> <hour> <minute> <second>\n\n");
				scanf(" %d %d %d %d %d %f", &p_apt->date_time.day, &p_apt->date_time.month, &p_apt->date_time.year, &p_apt->date_time.hour, &p_apt->date_time.minute, &p_apt->date_time.second);
				
				if (apt_val(*p_apt) != 0 || date_val(p_apt->date_time) != 0) {
					printf("Appointment data or date time data not accepted. Try again.\n\n");
					break;
				}

				if (counter == n_apts - 1) {
					n_apts *= n_apts;
					apts = realloc(apts, n_apts * sizeof(APT));
				}

				++p_apt;
				++counter;
				if (p_apt == apts) {
					*(p_apt) = add_apt(p_apt->name, p_apt->loc, p_apt->dur, p_apt->date_time);
				}
				
				if (compare_date_time((p_apt)->date_time, p_apt->date_time) == 0) {
					*(p_apt + 1) = add_apt(p_apt->name, p_apt->loc, p_apt->dur, p_apt->date_time);
				}

				*(p_apt + 1) = *(p_apt);
				*(p_apt) = add_apt(p_apt->name, p_apt->loc, p_apt->dur, p_apt->date_time); 
				break;

			case 'p':
				for (int i = 0; i < counter; ++i) {
					print_apt(*(apts + i));
				}
				break;

			case 'n':
				free(apts + start);
				++start;
				--counter;
				break;

			case 'q':
				for (int i = 0; i < n_apts; ++i) {
					free(apts + i);
				}
				is_quit = true;
				break;

			default:
				printf("Invalid command. Please try again.\n\n");
				break;
		}
	}

	return 0;
}