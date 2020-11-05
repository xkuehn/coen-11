#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main () {
	APT * head = NULL;
	APT * tail = NULL;
	APT * temp;

	bool run = true; 
	do {
		printf("\n* WHAT FUNCTION WOULD YOU LIKE TO PERFORM? *");
		printf("\n\tADD AN APPOINTMENT - a\n\tMOVE TO NEXT APPOINTMENT - n\n\tDELETE AN APPOINTMENT - d\n\tPRINT ALL APPOINTMENTS - p\n\tFIND AN APPOINTMENT - f\n\tQUIT - q\n");
		
		char c;
		scanf("%c", &c);
		while (getchar() != '\n');
		switch (c) {
			case 'a':
				head = push(head);
				continue;
			case 'n':
				head = next(head);
				print(head);
				continue;
			case 'd':
				head = delete_date(head);
				continue;
			case 'p':
				temp = head;
				do {
					print(temp);
					temp = temp->next;
				} while (temp);
				continue;
			case 'f':
				find(head);
				continue;
			case 'q':
				printf("\n* PROGRAM EXITED *\n");
				run = false;
				continue;
			default: 
				printf("\n* ERROR (main): FUNCTION NOT ACCEPTED OR RECOGNIZED PLEASE TRY AGAIN *\n");
				continue;
		}
	} while (run);
}