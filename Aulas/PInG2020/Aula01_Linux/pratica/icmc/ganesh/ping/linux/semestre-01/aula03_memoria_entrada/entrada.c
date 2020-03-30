// Programa que mostra como fazer entrada de dados via teclado
//
// Moacir A Ponti 2019

#include <stdio.h>

int main(void) {
	
	int num1 = 0;
	double num2 = 0.0;

	// funcao da stdio que permite obter valores de entrada
	// scanf ("formatacao", endereco)

	scanf("%d", &num1);
	printf("Valor digitado (num1) = %d\n", num1);

	// permitir que o usuario digite o valor de num2
	scanf("%lf", &num2);
	printf("Valor digitado (num2) = %lf\n", num2);

	return 0;
}
