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

void fun(char * p);

int main ( void)
{
    char * string[5] = "xyz";
    fun (string);
    return;
}

void fun (char *p)
{
    if (*p == '\0')
        return;
    else
    {
        printf ("%c", *p);
        printf ("%c", *p);
        fun (p + 1);
        printf ("%c", *p);
     }
     return;
}