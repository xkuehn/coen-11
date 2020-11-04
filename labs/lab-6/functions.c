#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void push (APT * head, APT * tail) {
	APT * apt;
	if ((apt = (APT *)malloc(sizeof(APT))) == (APT *)NULL) {
			printf("* ERROR: MEMORY COULD NOT BE ALLOCATED *\n");
			return;
	}

	apt = (APT *)malloc(sizeof(APT));
	DATE date;
	char * name;
	char * loc;
	int dur;
	unsigned char day;
	unsigned char month;
	unsigned char hour;
	unsigned char minute;
	float second;
	int year;

	printf("\nPlease input a name (50 chars max): ");
	fgets(name, 51, stdin);
	printf("\nPlease input a location (100 chars max): ");
	fgets(loc, 101, stdin);
	printf("\nPlease input a duration (in minutes): ");
	scanf(" %d", &dur);
	printf("\nPlease input a date <day> <month> <year> <hour> <minute> <second>: ");
	scanf(" %hhu %hhu %d %hhu %hhu %f", &day, &month, &year, &hour, &minute, &second);

	if (check(apt) != 0) {
		printf("\n* ERROR: INPUT NOT ACCEPTED PLEASE TRY AGAIN *");
		return;
	}

	apt->data.name = name;
	apt->data.loc = loc;
	apt->data.dur = dur;
	apt->data.date.day = day; 
	apt->data.date.month = month;
	apt->data.date.year = year;
	apt->data.date.hour = hour;
	apt->data.date.minute = minute;
	apt->data.date.second = second;

	if (head == NULL) {
		apt->next = head;
		head = apt;
		tail = apt;
		return;
	}

	APT * temp = head;
	while (temp->next) {
		if (compare(temp->data.date, temp->next->data.date) > 0) {
			temp = temp->next;
		} else if (compare(temp->data.date, temp->next->data.date) <= 0){
			apt->next = temp->next;
			temp->next = apt;
		}
	}
	if (temp->next == NULL) {
		tail = temp;
	}
	return;
}

void print (APT * apt) {
	printf("\nMeet %s at %s for %d minutes starting at ", apt->data.name, apt->data.loc, apt->data.dur);
	print_date(apt->data.date);
	printf(" until ");
	print_date(add_duration(apt, apt->data.dur));
	return;
}

int compare (DATE date1, DATE date2) {
	if (date1.year == date2.year) { return 0; }
	if (date1.month == date2.month) { return 0; }
	if (date1.day == date2.day) { return 0; }
	if (date1.minute == date2.minute) { return 0; }
	if (date1.hour == date2.hour) { return 0; }
	if (date1.second == date2.second) { return 0; }

	if (date1.year < date2.year) { return -1; }
	if (date1.month < date2.month) { return -1; }
	if (date1.day < date2.day) { return -1; }
	if (date1.minute < date2.minute) { return -1; }
	if (date1.hour < date2.hour) { return -1; }
	if (date1.second < date2.second) { return -1; }
	return 1;
}

int check (APT * apt) {
	int err;
	if (strlen(apt->data.name) <= 0) {err++;}
	if (strlen(apt->data.loc) <= 0) {err++;}
	if (apt->data.dur <= 0) {err++;}
	if (apt->data.date.month < 1 || apt->data.date.month > 12) {err++;}
	if (apt->data.date.year < 2020) {err++;}
	if (apt->data.date.day < 1) {err++;}
	if (apt->data.date.hour > 23 || apt->data.date.hour < 0) {err++;}
	if (apt->data.date.minute < 0 || apt->data.date.minute > 59) {err++;}
	if (apt->data.date.second < 0.0 || apt->data.date.second > 59.999999) {err++;}

	switch (apt->data.date.month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (apt->data.date.day > 31) {err++;}
			break;
		case 4: case 6: case 9: case 11:
			if (apt->data.date.day > 30) {err++;}
			break;
		case 2:
			if (apt->data.date.day > 28) {err++;}
			break;
		default:
			break; 
	}
	return err;
}

void print_date (DATE date) {
	char * month;
	char * time;
	unsigned char hour;

	if (date.hour > 12) {
		hour = date.hour - 12;
		time = "pm";
	} else {
		hour = date.hour; 
		time = "am";
	}

	switch (date.month) {
		case 1: month = "January"; break;
		case 2: month = "February"; break;
		case 3: month = "March"; break;
		case 4: month = "April"; break;
		case 5: month = "May"; break;
		case 6: month = "June"; break;
		case 7: month = "July"; break;
		case 8: month = "August"; break;
		case 9: month = "September"; break;
		case 10: month = "October"; break;
		case 11: month = "November"; break;
		case 12: month = "December"; break;
		default: break;
	}

	printf("%s %hhu %d at %hhu:%hhu:%.1f %s", month, date.day, date.year, hour, date.minute, date.second, time);	
	
	return;
}

DATE add_duration (APT * apt, int dur) {
	if (dur < 1 || dur > 40320) {
		printf("\n* ERROR: DURATION NOT ACCEPTED *");
		return apt->data.date;
	}

	DATE new_date = apt->data.date;
	apt->data.dur += dur;

	if (dur < 60) {
		if (new_date.minute < (60 - dur)) { new_date.minute += dur; }
			if (new_date.minute + dur > 59) {
				if (new_date.hour == 23) {
					switch (new_date.month) {
						case 2:
							if (new_date.day == 28) {
								++new_date.month;
								new_date.day = 1;
							}
						case 1: case 3: case 5: case 7: case 8: case 10:
							if (new_date.day == 31) {
								++new_date.month;
								new_date.day = 1; 
							}
						case 4: case 6: case 9: case 11:
							if (new_date.day == 30) {
								++new_date.month;
								new_date.day = 1; 
							}
						case 12:
							if (new_date.day == 31) {
								++new_date.year;
								new_date.month = 1;
								new_date.day = 1; 
							}
					}
				}
				++new_date.hour;
				new_date.minute = (new_date.minute + dur) - 60;	
			}
	} else if (dur < 1440) {
		if ((new_date.hour * 60) < (1440 - dur)) { new_date.hour += floor(dur / 60); }
			if ((new_date.hour * 60) + dur > 1439) {
				if (new_date.hour == 23) {
					switch (new_date.month) {
						case 2:
							if (new_date.day == 28) {
								++new_date.month;
								new_date.day = 1;
							}
						case 1: case 3: case 5: case 7: case 8: case 10:
							if (new_date.day == 31) {
								++new_date.month;
								new_date.day = 1; 
							}
						case 4: case 6: case 9: case 11:
							if (new_date.day == 30) {
								++new_date.month;
								new_date.day = 1; 
							}
						case 12:
							if (new_date.day == 31) {
								++new_date.year;
								new_date.month = 1;
								new_date.day = 1; 
							}
					}
				}
				++new_date.day;
				new_date.hour = floor((((new_date.hour * 60) + dur) - 1440) / 60);
			}
		} else if (dur < 40320) {
			if ((new_date.day * 1440) < (40320 - dur)) { new_date.day += floor(dur / 1440); }
			if ((new_date.day * 1440) + dur > 40329) {
				if (new_date.hour == 23) {
					switch (new_date.month) {
						case 2:
							if (new_date.day == 28) {
								++new_date.month;
								new_date.day = 1;
							}
						case 1: case 3: case 5: case 7: case 8: case 10:
							if (new_date.day == 31) {
								++new_date.month;
								new_date.day = 1; 
							}
						case 4: case 6: case 9: case 11:
							if (new_date.day == 30) {
								++new_date.month;
								new_date.day = 1; 
							}
						case 12:
							if (new_date.day == 31) {
								++new_date.year;
								new_date.month = 1;
								new_date.day = 1; 
							}
					}
				}
				++new_date.month;
				new_date.day = floor((((new_date.day * 1440) + dur) - 40320) / 1440);
			}
		}

	return new_date;
}

void next (APT * head) {
	if (head == NULL) {
		printf("\n* ERROR: THE LIST IS EMPTY // ADD AN APPOINTMENT TO CALL THIS FUNCTION *");
		return;
	}

	free(head);
	head = head->next;
}

void delete_date (APT * head, APT * tail) {
	if (head == NULL) {
		printf("\n* ERROR: THE LIST IS EMPTY // ADD AN APPOINTMENT TO CALL THIS FUNCTION *");
		return;
	}

	DATE date;
	printf("\nPlease input a date <day> <month> <year> <hour> <minute> <second>: ");
	scanf(" %hhu %hhu %d %hhu %hhu %f", &date.day, &date.month, &date.year, &date.hour, &date.minute, &date.second);

	APT * temp = head;
	APT * prev;
	while (compare(temp->data.date, date) != 0 && temp->next) {
		prev = temp;
		temp = temp->next;
	}

	if (temp->next == NULL) {
		prev->next = NULL;
		tail = prev;
	}

	prev->next = temp->next;
	free(temp);
	return;
}

void find (APT * head, APT * tail) {
	if (head == NULL) {
		printf("\n* ERROR: THE LIST IS EMPTY // ADD AN APPOINTMENT TO CALL THIS FUNCTION *");
		return;
	}

	DATE date;
	printf("\nPlease input a date <day> <month> <year> <hour> <minute> <second>: ");
	scanf(" %hhu %hhu %d %hhu %hhu %f", &date.day, &date.month, &date.year, &date.hour, &date.minute, &date.second);

	APT * temp = head;
	int i;
	while (compare(temp->data.date, date) != 0 && temp->next) {
		temp = temp->next;
		++i;
	}

	if (compare(temp->data.date, date) != 0) {
		printf("\n* ERROR: THE TARGET DATE WAS NOT FOUND IN THE LIST OF APPOINTMENTS *");
		return;
	}

	char * suffix;
	if (i == 1) { suffix = "st"; }
	if (i == 2) { suffix = "nd"; }
	if (i > 2) { suffix = "th"; }
	printf("\nThe appointment scheduled at the target date is %d%s in the list.", i, suffix);
	return;
}