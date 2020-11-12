#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix {
	unsigned int nrows;
	unsigned int ncols;
	double ** data;
} matrix;

matrix create_matrix(const unsigned int, const unsigned int);
void init_matrix(matrix);
void free_matrix(matrix);
void write_matrix(matrix, unsigned char);
void read_matrix(matrix, unsigned char);
void mod_matrix(matrix *);
void add_constant(matrix *, double);
matrix mul_matrix(matrix, matrix);

void read_val(matrix);
void mod_val(matrix);

int test_size(matrix);
int test_mul(matrix, matrix);
int test_vals(matrix);

#endif