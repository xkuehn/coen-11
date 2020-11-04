#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#define APT struct apt

typedef struct {
	unsigned char day;
	unsigned char month;
	int year;
	unsigned char hour;
	unsigned char minute;
	float second;
} DATE;

typedef struct {
	char * name;
	char * loc;
	int dur;
	DATE date;
} DATA;

struct apt {
	DATA data;
	APT * next;
};

void push (APT *, APT *);
void next (APT *);
void delete_date (APT *, APT *);
void print (APT *);
void print_date (DATE);
void find (APT *, APT *);
int compare (DATE, DATE);
int check (APT *);
DATE add_duration (APT *, int);

#endif