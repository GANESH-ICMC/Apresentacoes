#include <stdio.h>

void hack(void){
	printf("Hasked\n");
}

int main(int argc, char *argv[]){
	char str[10];
	scanf("%s", str);
	printf("Você digitou %s\n", str);
	return 0;	
}
