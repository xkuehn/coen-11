#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main () {
	
	APT * head = NULL;
	APT * tail = NULL;
	APT * temp = head;

	bool run = true; 
	while (run) {
		char c;
		printf("\n* WHAT FUNCTION WOULD YOU LIKE TO PERFORM? *");
		printf("\n\tADD AN APPOINTMENT - a\n\tMOVE TO NEXT APPOINTMENT - n\n\tDELETE AN APPOINTMENT - d\n\tPRINT ALL APPOINTMENTS - p\n\tFIND AN APPOINTMENT - f\n\tQUIT - q\n");
		scanf("%c", &c);

		if (c != 'a' || c != 'n' || c != 'd' || c != 'p' || c != 'f' || c != 'q') {
			printf("\n* ERROR: FUNCTION NOT ACCEPTED OR RECOGNIZED PLEASE TRY AGAIN *\n");
			continue;
		}

		switch (c) {
			case 'a':
				push(head, tail);
				continue;
			case 'n':
				next(head);
				continue;
			case 'd':
				delete_date(head, tail);
				continue;
			case 'p':
				while (temp) {
					print(temp);
				}
				continue;
			case 'f':
				find(head, tail);
				continue;
			case 'q':
				printf("\n* PROGRAM EXITED *\n");
				run = false;
				continue;
			default: continue;
		}
	}
}