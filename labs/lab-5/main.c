#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "functions.h"

int main() {
	
	int count = 0, head = 0, back = 0;
	int n_apts = 5;
	APT * apts = (APT *)malloc(n_apts * sizeof(APT));
	APT * p_apt = (apts + back);

	bool is_quit = false;
	while (is_quit != true) {

		printf ("Please enter a command to begin:\n");
		printf ("a - add an appointment\n");
		printf ("p - print all appointments\n");
		printf ("d - delete all appointments\n");
		printf ("q - quit\n");

		char command;
		scanf("%c", &command);

		switch (command) {

			case 'a':
				
				printf("Number of appointments: %d\n", count);
				if (count == n_apts - 1) {
					n_apts = n_apts * 2;
					apts = (APT *)realloc(apts, n_apts);
				}

				printf("Please input doctor's name: ");
				fgetc(stdin);
				fgets(p_apt->name, NAME_LENGTH, stdin);
				printf("Please input location: ");
				fgetc(stdin);
				fgets(p_apt->loc, LOC_LENGTH, stdin);
				printf("Please input duration: ");
				scanf("%d", &p_apt->dur);
				printf("Please input date and time int the format <day> <month> <year> <hour> <minute> <second>:\n");
				scanf("%d %d %d %d %d %f", &p_apt->date_time.day, &p_apt->date_time.month, &p_apt->date_time.year, &p_apt->date_time.hour, &p_apt->date_time.minute, &p_apt->date_time.second);
				
				if (apt_val(p_apt) != 0) {
					printf("Appointment data not accepted please try again.\n");
					break;
				}

				//printf("%d\n", count);

				++back;
				++count;

				break;
				
			case 'p':
				for (int i = 0; i < count; ++i) {
					print_apt(apts + i);
					printf("\n");
				}
				break;
			case 'd':
				for (int i = count; i > 0; --i) {
					free(apts + i);
				}
				break;
			case 'q':
				for (int i = count; i > 0; --i) {
					free(apts + i);
				}
				is_quit = true;
				break;
			default:
				break;
		}
	}
	return 0;
}