// Programa que demonstra o uso da memoria stack / pilha
// e tipos de dados
// Moacir A Ponti 2019

#include <stdio.h>

int main(void) {

	int A;  // variavel com identificador 'A', tipo int (4 bytes)
	char B; // variavel com identificador 'B', tipo char (1 byte)

	// armazena valores na memoria usando as variaveis criadas
	A = 254; 
	B = '@';

	// imprime na tela os valores
	// printf("formatacao %? %?", variavel1, variavel2, ...);
	printf("Valores armazenados:\n");

	// os operadores % posicionam, na ordem, as variaveis na
	// formatacao a ser exibida na tela
	printf("A = %d, B = %c\n", A, B);

	printf("Enderecos das variaveis:\n");
	
	// operador & que extrai o endereco da variavel		
	printf("&A = %p\n&B = %p\n", &A, &B);

	// posso armazenar enderecos de memoria em variaveis!
	// 1.o - qual o tamanho (em bytes) de um endereco?
	// 	 do mesmo tamanho que a arquitetura do sistema
	//	 atualmente, 64 bits ou 8 bytes
	// 2.o - todo endereco deve ser interpretado igualmente?
	//	 depende do tipo de dado armazenado nesse endereco

	// para armazenar um endereco, basta criar uma variavel
	// do tipo desejado, indicando um asterisco na frente
	// tipo* var;

	int* endA;
	endA = &A; // nao funciona! porque &A tem 64 e endA 32 bits

	printf("Mostrando endereco armazenado em endA: %p\n", endA);
	printf("Mostrando endereco da variavel endA  : %p\n",&endA);
	
	char* endB;
	endB = &B;
	
	printf("Mostrando endereco armazenado em endB: %p\n", endB);
	printf("Mostrando endereco da variavel endB  : %p\n",&endB);
	

	return 0;
}
