#import "matrix.h"
#import <stdio.h>
#import <stdlib.h>
#import <string.h>

int main () {
	//create matrix
	matrix mat1 = create_matrix(2, 2);
	read_val(mat1);
	//add constant to matrix
	add_constant(&mat1, 2);
	//read value at index
	read_val(mat1);

	// for (int i = 0; i < mat1.nrows; ++i) {
	// 	for (int j = 0; j < mat1.ncols; ++j) {
	// 		printf("%.2lf ", mat1.data[i][j]);
	// 	}
	// 	printf("\n");
	// }

	matrix mat2 = create_matrix(2, 3);
	read_val(mat2);
	add_constant(&mat2, 5);
	mod_val(mat2);

	// for (int i = 0; i < mat2.nrows; ++i) {
	// 	for (int j = 0; j < mat2.ncols; ++j) {
	// 		printf("%.2lf ", mat2.data[i][j]);
	// 	}
	// 	printf("\n");
	// }

	matrix res = mul_matrix(mat1, mat2);
	printf("%u %u\n", res.nrows, res.ncols);
	
	write_matrix(mat1, 0);
	write_matrix(mat2, 1);
	read_matrix(mat1, 0);
	read_matrix(mat2, 1);
	write_matrix(res, 0);
	read_matrix(res, 0);
	free_matrix(mat1);
	free_matrix(mat2);
	free_matrix(res);
}