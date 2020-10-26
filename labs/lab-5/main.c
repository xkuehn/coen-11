#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

int main() {
	
	int n_apts = 5;
	APT * apts = (APT *)malloc(n_apts * sizeof(APT)); // allocates memory for list
	// p_apt->name = malloc(sizeof(char) * NAME_LENGTH);
	// p_apt->loc = (char *)malloc(sizeof(char) * LOC_LENGTH);
	// p_apt = apts;
	// p_apt->dur = (int)malloc(sizeof(int));
	// p_apt->date_time.day = (int)malloc(sizeof(int));
	// p_apt->date_time.month = (int)malloc(sizeof(int));
	// p_apt->date_time.year = (int)malloc(sizeof(int));
	// p_apt->date_time.minute = (int)malloc(sizeof(int));
	// p_apt->date_time.hour = (int)malloc(sizeof(int));
	// p_apt->date_time.second = (float)(int)malloc(sizeof(float));

	int start = 0, counter = 0, back = 0; // variables to track the circular list
	bool is_quit = false;

	while (is_quit == false) {

		char command;
		printf("\n Choose a command:\na - add an appointment\np - print list of appointments\nn - next appointment\nq - quit program\n");

		scanf("%c", &command);
		switch (command) {
			case 'a':
				printf("Input data for an appointment: <name> ");
				fgets((apts + back)->name, NAME_LENGTH, stdin);
				printf("Input data for an appointment: <location> ");
				fgets((apts + back)->loc, LOC_LENGTH, stdin);
				printf("Input data for an appointment: <duration> ");
				scanf(" %d", &(apts + back)->dur);
				printf("Input date and time for appointment: <day> <month> <year> <hour> <minute> <second>\n");
				scanf(" %d", &((apts + back)->date_time.day));
				printf("Input date and time for appointment: <month> ");
				scanf(" %d", &((apts + back)->date_time.month));
				printf("Input date and time for appointment: <year> ");
				scanf(" %d", &((apts + back)->date_time.year));
				printf("Input date and time for appointment: <hour> ");
				scanf(" %d", &((apts + back)->date_time.hour));
				printf("Input date and time for appointment: <minute> ");
				scanf(" %d", &((apts + back)->date_time.minute));
				printf("Input date and time for appointment: <second> ");
				scanf(" %f", &((apts + back)->date_time.second));


				if (apt_val(*(apts + back)) != 0 || date_val((apts + back)->date_time) != 0) {
					printf("\nAppointment data or date time data not accepted. Try again.\n");
					continue;
				}

				if (counter == n_apts - 1) {
					n_apts *= n_apts;
					apts = realloc(apts, n_apts * sizeof(APT));
				}

				if ((apts + back) == apts) {
					*((apts + back)) = add_apt((apts + back)->name, (apts + back)->loc, (apts + back)->dur, (apts + back)->date_time);
				}
				
				if (compare_date_time((apts + back)->date_time, (apts + back)->date_time) == 0) {
					*((apts + back) + 1) = add_apt((apts + back)->name, (apts + back)->loc, (apts + back)->dur, (apts + back)->date_time);
				}

				*((apts + back) + 1) = *(apts + back);
				*((apts + back)) = add_apt((apts + back)->name, (apts + back)->loc, (apts + back)->dur, (apts + back)->date_time); 
				++back;
				++counter;
				break;

			case 'p':
				for (int i = 0; i < counter; ++i) {
					print_apt(*(apts + i));
				}
				break;

			case 'n':
				//free(apts + start);
				++start;
				--counter;
				break;

			case 'q':
				// for (int i = 0; i < n_apts; ++i) {
				// 	free(apts + i);
				// }
				is_quit = true;
				break;

			default:
				printf("Invalid command. Please try again.\n");
				break;
		}
	}

	return 0;
}