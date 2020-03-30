#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Exercicio: alterar esse programa de forma que
	sejam sorteados numeros entre 1 e 100

	e que, a cada vez que o usuario digita o numero,
	caso ele nao acerte, exiba na tela uma dica, dizendo
	se o numero sorteado e' maior ou menor do que o 
	digitado
*/

int main (void) {

	// funcao que define a semente
	srand(time(NULL));

	// sorteia um numero e modifica de forma que fique no intervalo 1-20
	int numero;
	numero = (rand() % 20) + 1;

	// imprime na tela o aviso para o usuario
	printf("Adivinhe o numero sorteado, de 1 a 20:\n");

	// declara variavel e permite que o usuario digite um valor
	int usuario = 0;

	// verifica se o numero digitado e' igual ao sorteado
	/* // da' so' uma chance
	
	scanf("%d", &usuario);
	if (numero == usuario) {
		printf("Acertou\n");
	}
	else {
		printf("Errou\n");
	}
	*/

	// enquanto o numero for diferente do sorteado
	while (numero != usuario) {
		// usuario tenta adivinhar
		scanf("%d", &usuario);
	}
	printf("Acertou\n");

	return 0;
}
