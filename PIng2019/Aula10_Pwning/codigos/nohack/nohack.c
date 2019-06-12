#include <stdio.h>


int main(int argc, char *argv[]){
	char str[64];
	printf("%p", str);
	scanf("%s", str);
	printf("Você digitou %s\n", str);
	return 0;	
}
