#include <stdio.h>


int main(void){
	volatile int i = 10;
	char str[10];
	scanf("%s", str);
	printf("Bem vindo %s\n", str);
	printf("i = %x", i);
	if (i != 10){
		printf("Haha\n");
	}
	return 0;
}
