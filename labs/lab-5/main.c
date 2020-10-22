#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

int main() {
	
	int n_apts = 5;
	APT * apts = (APT *)malloc(n_apts * sizeof(APT));
	int start = 0, back = 0, counter = 0; // variables to track the circular list
	bool is_quit = false;

	while (is_quit == false) {

		APT temp_apt;
		DATE_TIME temp_date_time;
		char command;
		printf("Choose a command:\na - add an appointment\np - print list of appointments\nn - next appointment\nq - quit program\n");

		scanf("%c", &command);
		switch (command) {
			case 'a':
				printf("Input data for an appointment: <name> <location> <duration>\n");
				scanf("%s%*c%s%*c%d", temp_apt.name, temp_apt.loc, &temp_apt.dur);
				printf("Input date and time for appointment: <day> <month> <year> <hour> <minute> <second>\n");
				scanf("%d%*c%d%*c%d%*c%d%*c%d%*c%f", &temp_date_time.day, &temp_date_time.month, &temp_date_time.year, &temp_date_time.hour, &temp_date_time.minute, &temp_date_time.second);
				
				if (apt_val(temp_apt) != 0 || date_val(temp_date_time) != 0) {
					printf("Appointment data or date time data not accepted. Try again.\n");
					break;
				}

				if (counter == n_apts - 1) {
					n_apts *= n_apts;
					realloc(apts, n_apts * sizeof(APT));
				}

				if (back < 1) {
					*(apts + back) = add_apt(temp_apt.name, temp_apt.loc, temp_apt.dur, temp_date_time);
				}
				
				if (compare_date_time((apts + back)->date_time, temp_date_time) == 0) {
					*(apts + back + 1) = add_apt(temp_apt.name, temp_apt.loc, temp_apt.dur, temp_date_time);
				}

				*(apts + back + 1) = *(apts + back);
				*(apts + back) = add_apt(temp_apt.name, temp_apt.loc, temp_apt.dur, temp_date_time); 

				++back;
				++counter;
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
				free(apts);
				is_quit = true;
				break;

			default:
				printf("Invalid command. Please try again.\n\n");
				break;
		}
	}

	return 0;
}