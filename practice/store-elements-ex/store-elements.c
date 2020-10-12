#include <stdio.h>

int main(void){

    int arr[10];
    int input = 1;
    
	for(int i = 0; i < sizeof(arr)/sizeof(input); i++){
		arr[i] = input;
		printf("%d\t", arr[i]);
		input++;
	}
}
