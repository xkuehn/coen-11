#import <stdio.h>

// 	SET POINTER TO VALUE OF OTHER POINTER
// int main(){

// 	int i = 1, j = 5;
// 	int *ip = &i;
// 	int *jp = ip;

// 	printf("%p\t%p", ip, jp);
// 	return 0;
// }


// 	HANDLING POINTERS IN A PROGRAM
// int main(){

// 	int m = 29;
// 	printf("Address of m: %p\nValue of m: %d\n", &m, m);

// 	int * ab = &m;
// 	printf("Now ab is assigned with the address of m.\nAddress of pointer ab: 
// 		%p\nContent of pointer ab: %d\n", ab, *ab);

// 	m = 34;
// 	printf("The value of m is assigned to %d now.\nAddress of pointer ab: 
// 		%p\nContent of pointer ab: %d\n", m, ab, *ab);
	
// 	*ab = 7;
// 	printf("The pointer variable ab is assigned with the value %d now.\nAddress of m: 
// 		%p\nValue of m: %d\n", *ab, &m, m);	 
// }

//	USING & AND * OPERATORS
// int main(){

// 	int m = 300;
// 	int * mp = &m;
// 	double fx = 300.600006;
// 	double * fxp = &fx;
// 	char ch = 'z';
// 	char * chp = &ch; 

// 	printf("Pointer : Demonstrate the use of & and * operator :\n---------------------------------------------------\n");
// 	printf("Using & operator :\n------------------\n");
// 	printf("address of m = %p\n", &m);
// 	printf("address of fx = %p\n", &fx);
// 	printf("address of ch = %p\n\n", &ch);

// 	printf("Using & and * operator :\n------------------------\n");
// 	printf("value at address of m = %d\n", *(&m));
// 	printf("value at address of fx = %lf\n", *(&fx));
// 	printf("value at address of ch = %c\n\n", *(&ch));

// 	printf("Using only pointer variable :\n-----------------------------\n");
// 	printf("value at address of m = %p\n", mp);
// 	printf("value at address of fx = %p\n", fxp);
// 	printf("value at address of ch = %p\n\n", chp);

// 	printf("Using only pointer operator :\n-----------------------------\n");
// 	printf("value at address of m = %d\n", *mp);
// 	printf("value at address of fx = %lf\n", *fxp);
// 	printf("value at address of ch = %c\n\n", *chp);
// }

//	ADDING 2 NUMBERS USING POINTERS
// int main(){

// 	int first = 5;
// 	int * firstp = &first;
// 	int second = 6;
// 	int * secondp = &second;

// 	int sum = *firstp + *secondp;
// 	printf("The sum of the first and second value is: %d\n", sum);
// }

//  COPY CONTENT OF ARRAY TO ANOTHER ARRAY
// int main(){

//     int size = 5;

//     int arr[] = {0,1,2,3,4};
//     int * parr = arr;
//     int copy[size];
//     int *pcopy = copy;

//     for (int i = 0; i < size; ++i) {
//         *(pcopy + i) = *(parr + i); 
//     }

//     for (int i = 0; i < size; ++i) {
//         printf("%d\t", *(pcopy + i));
//     }
// }

//  FIND LENGTH OF STRING
// int main(){

//     char str[] = "I love jennifer so much!";
//     char * pstr = str;
//     int i = 0, count = 0;

//     while (*(pstr + i) != '\0') {

//         ++count;
//         ++i;

//     }

//     printf("Length of string: %d\n", count);
// }

//  COMPARE 2 STRINGS USING POINTERS
// int compare(char * str1, char * str2);

// int main () {

//     char * str1 = "Hello";
//     char * str2 = "Hello";
//     int res;

//     res = compare(str1, str2);

//     if (res == 0) {
//         printf("Both strings are equal.\n");
//     }
//     if (res > 0) {
//         printf("String one is larger than string two by %d characters.\n", res - 1);
//     }
//     if (res < 0) {
//         printf("String two is larger than string one by %d characters.\n", res*(-1) - 1);
//     }
// }

// int compare (char * str1, char * str2) {

//     while ((*str1 && *str2) && (*str1 == *str2)) {
//         str1++;
//         str2++;
//     }

//     return *str1 - *str2;
// }








































