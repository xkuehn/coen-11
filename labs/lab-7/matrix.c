#import "matrix.h"
#import <stdio.h>
#import <stdlib.h>
#import <string.h>

matrix create_matrix(const unsigned int r, const unsigned int c) {
	matrix mat;
	mat.nrows = r;
	mat.ncols = c;
	mat.data = (double **)malloc(sizeof(double *) * mat.nrows);
	for (int i = 0; i < mat.nrows; ++i) {
		mat.data[i] = (double *)malloc(sizeof(double) * mat.ncols);
	}
	init_matrix(mat);
	return mat;
}

void init_matrix(matrix mat) {
	for (int i = 0; i < mat.nrows; ++i) {
		for (int j = 0; j < mat.ncols; ++j) {
			mat.data[i][j] = 0;
		}
	}
	return;
}

void free_matrix(matrix mat) {
	for (int i = 0; i < mat.nrows; ++i) {
		free(mat.data[i]);
	}
	free(mat.data);
	return;
}

void add_constant(matrix * mat, double c) {
	for (int i = 0; i < mat->nrows; ++i) {
		for (int j = 0; j < mat->ncols; ++j) {
			mat->data[i][j] += c;
		}
	}
	return;
}

matrix mul_matrix(matrix mat1, matrix mat2) {
	matrix res = create_matrix(mat1.nrows, mat2.ncols);
	res.nrows = mat1.nrows;
	res.ncols = mat2.ncols;
	if (test_mul(mat1, mat2) != 0) {
		return res;
	}

	// printf("hi\n");
	// for (int i = 0; i < mat1.nrows; ++i) {
	// 	for (int j = 0; j < mat1.ncols; ++j) {
	// 		printf("%.2lf ", mat1.data[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// for (int i = 0; i < mat2.nrows; ++i) {
	// 	for (int j = 0; j < mat2.ncols; ++j) {
	// 		printf("%.2lf ", mat2.data[i][j]);
	// 	}
	// 	printf("\n");
	// }

	for (int i = 0; i < mat1.nrows; ++i) {
		for (int j = 0; j < mat2.ncols; ++j) {
			for (int k = 0; k < mat1.ncols; ++k) {
				res.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
			}
		}
	}
	return res;
}

void write_matrix(matrix mat, unsigned char type) {
	char file_name[50];
	char * ext;
	FILE * outfp;

	if (type == 0) {
		ext = ".txt";
		printf("\nWhat file would you like to write to? ");
		scanf("%[^'\n']", file_name);
		fpurge(stdin);

		strcat(file_name, ext);
		printf("%s\n", file_name);
		if ((outfp = fopen(file_name, "w")) == NULL) {
			printf("\nerror: cannot open the file %s\n", file_name);
		}

		for (int i = 0; i < mat.nrows; ++i) {
			for (int j = 0; j < mat.ncols; ++j) {
				fprintf(outfp, "%lf ", mat.data[i][j]);
			}
			fprintf(outfp, "\n");
		}
		fclose(outfp);
	} else {
		ext = ".bin";
		printf("\nWhat file would you like to write to? ");
		scanf("%[^'\n']", file_name);
		fpurge(stdin);

		strcat(file_name, ext);
		if ((outfp = fopen(file_name, "wb")) == NULL) {
			printf("\nerror: cannot open the file %s\n", file_name);
		}

		fwrite(&mat, sizeof(matrix), 1, outfp);
		fclose(outfp);
	}
	return;
}

void read_matrix(matrix mat, unsigned char type) {
	char file_name[50];
	char * ext;
	FILE * infp;

	if (type == 0) {
		ext = ".txt";
		printf("\nWhat file would you like to read? ");
		scanf("%[^'\n']", file_name);
		fpurge(stdin);

		strcat(file_name, ext);
		if ((infp = fopen(file_name, "rb")) == NULL) {
			printf("\nerror: cannot open the file %s\n", file_name);
		}
		
		for (int i = 0; i < mat.nrows; ++i) {
			for (int j = 0; j < mat.ncols; ++j) {
				fscanf(infp, "%lf ", &mat.data[i][j]);
			}
		}
	} else {
		ext = ".bin";
		printf("\nWhat file would you like to read? ");
		scanf("%[^'\n']", file_name);
		fpurge(stdin);

		strcat(file_name, ext);
		if ((infp = fopen(file_name, "rb")) == NULL) {
			printf("\nerror: cannot open the file %s\n", file_name);
		}
		
		fread(&mat, sizeof(matrix), 1, infp);
	}
	fclose(infp);
	return;
}

void read_val(matrix mat) {
	int row;
	int col;

	printf("\nInput location <row> <col>: ");
	scanf("%d %d", &row, &col);
	fpurge(stdin);

	printf("\nValue at [%d][%d]: %.2lf\n", row, col, mat.data[row - 1][col - 1]);
	return;
}

void mod_val(matrix mat) {
	double val;
	int row;
	int col;

	printf("\nInput new value and location <val> <row> <col>: ");
	scanf("%lf %d %d", &val, &row, &col);
	fpurge(stdin);

	mat.data[row - 1][col - 1] = val;
	return;
}

int test_size(matrix mat) {
	if (mat.nrows < 1) {
		return 1;
	}
	if (mat.ncols < 1) {
		return 1;
	}
	return 0;
}

int test_mul(matrix mat1, matrix mat2) {
	if (mat1.ncols != mat2.nrows) {
		return 1;
	}
	return 0;
}

int test_vals(matrix mat) {
	int e = 0;
	for (int i = 0; i < mat.nrows; ++i) {
		for (int j = 0; j < mat.ncols; ++j) {
			if (mat.data[i][j] == 0) {
				e++;
			}
		}
	}

	if (e > 0) {
		return 1;
	}
	return 0;
}


















