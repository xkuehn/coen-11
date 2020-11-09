#ifndef FUNCTIONS_H
#define FUNCIIONS_H

#define num struct num

typedef struct {
	unsigned int cid;
	double val;
} data;

struct num {
	data d;
	num * next;
}

typedef struct {
	num * head;
	num * tail;
	unsigned int size;
} list;

typedef struct {
	list ** rows;
	unsigned int nrows;
	unsigned int ncols;
} matrix;

matrix * create_m (const unsigned int, const unsigned int);
void free_m (matrix *)
void print_m (matrix *);
void analyze_m (matrix *);

list * create_l ();
void free_l (list *);
void print_l (list *);

void add_e (matrix *, double, unsigned int);


void transpose (matrix *);
int next_m (matrix *);

void add_c (matrix *, double);
void sub_c (matrix *, double);
void mul_c (matrix *, double);
void div_c (matrix *, double);

/* I'm not sure how to write the linear algebra operations for 2 matrices yet but I will continue to work on it over the next week. I am also unsure about how an element should be added and how the next() function should work */

#endif