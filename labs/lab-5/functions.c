#include "functions.h"
#include <string.h>
#include <stdio.h>
#include <math.h>

APT add_apt(char name[NAME_LENGTH], char loc[LOC_LENGTH], int dur, DATE_TIME date_time) {

	APT apt = {*name, *loc, dur};
	apt.date_time = date_time;
	return apt;
}

int compare_date_time(DATE_TIME date_time1, DATE_TIME date_time2){

	if (date_time1.year < date_time2.year || date_time1.month < date_time2.month) {
		return 0;
	}

	if (date_time1.day < date_time2.day || date_time1.hour < date_time2.hour) {
		return 0;
	}

	if (date_time1.minute < date_time2.minute || date_time1.second < date_time2.second) {
		return 0;
	}

	return 1;
}

void print_apt(APT * apts) {
	
	printf("Meet Dr. %s", apts->name);
	printf(" at %s for %d minutes starting at ", apts->loc, apts->dur);
	print_date_time(apts->date_time);
	printf(" until ");
	print_date_time(add_duration(apts, apts->dur));

}

int apt_val(APT * apt) {
	
	int err;
	if (strlen(apt->name) <= 0) {err++;}

	if (strlen(apt->loc) <= 0) {err++;}

	if (apt->dur <= 0) {err++;}

	if (apt->date_time.month < 1 || apt->date_time.month > 12) {err++;}

	if (apt->date_time.year < 2020) {err++;}

	if (apt->date_time.day < 1) {err++;}

	if (apt->date_time.hour > 23 || apt->date_time.hour < 0) {err++;}

	if (apt->date_time.minute < 0 || apt->date_time.minute > 59) {err++;}

	if (apt->date_time.second < 0.0 || apt->date_time.second > 59.999999) {err++;}

	switch (apt->date_time.month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (apt->date_time.day > 31) {err++;}
			break;
		case 4: case 6: case 9: case 11:
			if (apt->date_time.day > 30) {err++;}
			break;
		case 2:
			if (apt->date_time.day > 28) {err++;}
			break;
		default:
			break; 
	}

	return err;
}

// int date_val(DATE_TIME date_time) {
	
// 	int err;
// 	if (date_time.month < 1 || date_time.month > 12) {err++;}

// 	if (date_time.year < 2020) {err++;}

// 	if (date_time.day < 1) {err++;}

// 	if (date_time.hour > 23 || date_time.hour < 0) {err++;}

// 	if (date_time.minute < 0 || date_time.minute > 59) {err++;}

// 	if (date_time.second < 0.0 || date_time.second > 59.999999) {err++;}

// 	switch (date_time.month) {
// 		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
// 			if (date_time.day > 31) {err++;}
// 			break;
// 		case 4: case 6: case 9: case 11:
// 			if (date_time.day > 30) {err++;}
// 			break;
// 		case 2:
// 			if (date_time.day > 28) {err++;}
// 			break;
// 		default:
// 			break; 
// 	}

// 	return err;
// }

void print_date_time(DATE_TIME date_time) {

	char * month;
	char * day_night;
	int hour;

	if (date_time.hour > 12) {
		hour = date_time.hour - 12;
		day_night = "pm";
	} else {
		hour = date_time.hour; 
		day_night = "am";
	}

	switch (date_time.month) {
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

	printf("%s %d %d at %d:%d:%.1f %s", month, date_time.day, date_time.year, hour, date_time.minute, date_time.second, day_night);	
	
	return;
}

DATE_TIME add_duration(APT * apt, int dur) {
	
	if (dur < 1 || dur > 40320) {
		return apt->date_time;
	}
	
	apt->dur += dur;
	DATE_TIME new_date_time = apt->date_time;

	if ((new_date_time.minute + dur) > 59) {
		if ((new_date_time.hour + (floor(dur / 60))) > 23) {
			if ((new_date_time.day + (floor(dur / 1440))) > 28) {
				if((new_date_time.month + (floor(dur / 40320))) > 12) {
					++new_date_time.year;
				}
				new_date_time.month += floor(dur / 40320);
				new_date_time.day = dur % 40320;
				new_date_time.hour = (dur % 40320) % 1440;
				new_date_time.minute = ((dur % 40320) % 1440) % 60;
			}
			new_date_time.day += floor(dur / 1440);
			new_date_time.hour = dur % 1440;
			new_date_time.minute = (dur % 1440) % 60;
		}
		new_date_time.hour += floor(dur / 60);
		new_date_time.minute = dur % 60;
		return new_date_time;
	}
	new_date_time.minute += dur;

	return new_date_time;
}