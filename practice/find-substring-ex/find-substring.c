#import <stdio.h>

char * find_substr_ptr (const char * str, const char * substr);

int main(){
	printf("%s\n", find_substr_ptr("yaxybbxccxyddx", "xy"));
	printf("%s\n", find_substr_ptr("yaxybbxccxyddx", "cc"));
	printf("%s\n", find_substr_ptr("yaxybbxccxyddx", "dx"));
	printf("%s\n", find_substr_ptr("yaxybbxccxyddx", "xa"));
}

char * find_substr_ptr (const char * str, const char * substr){

	int i = 0, j;
	while(str != NULL){
		j = 0;
		while((substr + j) != NULL){
			if((substr + j) != (str + i + j)){
				break;
			}
			j++;
		}
		if(substr + j == NULL){
			return (char*)substr;
		}
		i++;
	}
	return (char*)str;
}