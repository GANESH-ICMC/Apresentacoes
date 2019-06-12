#include <stdio.h>

void hack(void){
	printf("Hasked\n");
}

int main(int argc, char *argv[]){
	char str[64];
	printf("%p\n", hack);
	scanf("%s", str);
	printf("Você digitou %s\n", str);
	return 0;	
}
