#include <stdio.h>

int main (void) {

	int inicial = 1;

	// loop infinito
	/*
	while (inicial == 1) {
		printf("Estou dentro do loop\n");
	}
	*/

	int final = 0;
	scanf("%d", &final);

	while (inicial <= final) {
		printf("%d ", inicial);
		inicial = inicial + 1;
	}
	printf("\n");


	return 0;
}
