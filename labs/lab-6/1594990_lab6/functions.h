#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define APT struct apt
#define NAME_LENGTH 50
#define LOC_LENGTH 100

typedef struct {
	unsigned char day;
	unsigned char month;
	int year;
	unsigned char hour;
	unsigned char minute;
	float second;
} DATE;

typedef struct {
	char name[NAME_LENGTH];
	char loc[LOC_LENGTH];
	int dur;
	DATE date;
} DATA;

struct apt {
	DATA data;
	APT * next;
};

APT * push (APT *);
APT * next (APT *);
APT * delete_date (APT *);
void print (APT *);
void print_date (DATE);
void find (APT *);
int compare (DATE, DATE);
int check (APT *);
DATE add_duration (DATE, int);

#endif