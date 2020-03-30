

#include <stdio.h>

int main(void) {

	// valor hard-coded
	int var = 1;
	
	float x = 0.0;

	switch (var) {

		case 1: x = 10.0;
			break;

		case 2: x = 20.0;
			break;

		case 3: x = 30.0;
			break;

		default: x = -1.0;


	}
	// a instrucao 'break' leva o codigo ate aqui.

	printf("Apos o switch:\n");
	printf("%d %f\n", var, x);


	if (var == 1) {
		x = 10.0;
		// break; // isso da erro porque break nao pode ser usado dentro de IF
		x = 20.0;
		x = 30.0;
	}
	printf("Apos o IF:\n");
	printf("%d %f\n", var, x);



	return 0;
}
