#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define NAME_LENGTH 30
#define LOC_LENGTH 50

typedef struct date_time {
	int day;
	int month;
	int year;
	int hour;
	int minute;
	float second;
} DATE_TIME;

typedef struct apt {
	char name[NAME_LENGTH];
	char loc[LOC_LENGTH];
	int dur;
	DATE_TIME date_time;
} APT;

APT add_apt(char[], char[], int, DATE_TIME);

int compare_date_time(DATE_TIME, DATE_TIME);

void print_apt(APT *);

int apt_val(APT *);

void print_date_time(DATE_TIME);

DATE_TIME add_duration(APT*, int);

#endif