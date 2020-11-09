#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <assert.h>

list * create_l () {
	list * lst = (list *)malloc(sizeof(list));
	memset(lst, 0, sizeof(list));
	return lst;
}

void free_l (list * lst) {
	list * tmp = lst->head;
	while (lst->head) {
		tmp = lst->head;
		lst->head = tmp->next;
		free(tmp);
	}
	free(lst);
	return;
}

matrix * create_m(const unsigned int nrows, const unsigned int ncols) {
	matrix * mat = (matrix *)malloc(sizeof(matrix));
	mat->nrows = nrows;
	mat->ncols = ncols;
	mat->rows = (list **)malloc(sizeof(list *) * nrows);
	for (int i = 0; i < nrows; ++i) {
		rows[i] = create_l();
	}
	return mat;
}

void free_m (matrix * mat) {
	for (int i = 0; i < mat->nrows; ++i) {
		free_l(mat->rows[i]);
	}
	free(mat->rows);
	free(mat);
	return;
}

int next_m () {
	return 1;
}

void add_e (matrix * mat, double val) {
	int col;
	int row;

	// while (mat->rows[row]->tail) {
	// 	if (row == mat->nrows) {
	// 		mat->nrows *= 2;
	// 	}
	// 	row++;
	// }

	if (!mat->rows[row]->head) {
		mat->rows[rid]->head->d.val = val;
		mat->rows[rid]->head->d.cid = col;
		return;
	}

	num * temp = mat->rows[rid]->head;
	while (temp->d.val) {
		if (col == mat->ncols) {
			//move on to next row
		}
		col++;
		temp = temp->next;
	}

	mat->rows[rid]->temp->d.val = val;
	mat->rows[rid]->temp->d.cid = col;
	return;
}

void print_l (list * lst) {
	num * temp = lst->head;
	while (temp) {
		printf("Value: %lf, Column ID: %u\n", temp->val, temp->cid);
		temp = temp->next;
	}
}

void print_m (matrix * mat) {
	int i = 0;
	while (mat->rows[i]) {
		printf("-ROW %d-\n", i);
		print_l(mat->rows[i]);
		++i;
	}
}
// void analyze_m (matrix * mat) {}
// void transpose (matrix * mat) {}

void add_c (matrix * mat, double val) {
	int i, j;
	while (i < mat->nrows) {
		num * temp = mat->rows[i]->head;
		if (j == mat->ncols - 1) {
			++i;
			j = 0;
		}

		temp->d.val += val;
		temp = temp->next;
		++j;
	}
}
void sub_c (matrix * mat, double val) {
	int i, j;
	while (i < mat->nrows) {
		num * temp = mat->rows[i]->head;
		if (j == mat->ncols - 1) {
			++i;
			j = 0;
		}

		temp->d.val -= val;
		temp = temp->next;
		++j;
	}
}

void mul_c (matrix * mat, double val) {
	int i, j;
	while (i < mat->nrows) {
		num * temp = mat->rows[i]->head;
		if (j == mat->ncols - 1) {
			++i;
			j = 0;
		}

		temp->d.val *= val;
		temp = temp->next;
		++j;
	}
}

void div_c (matrix * mat, double val) {
	int i, j;
	while (i < mat->nrows) {
		num * temp = mat->rows[i]->head;
		if (j == mat->ncols - 1) {
			++i;
			j = 0;
		}

		temp->d.val /= val;
		temp = temp->next;
		++j;
	}
}