#include <stdio.h>

// funcao principal 
int main (void) {

	int a; // reserva um bloco de 4 bytes na memoria
	a = 50; // armazena o valor 50 nesse bloco

	printf("%d\n",  a); // escreve o valor contido em 'a' na saida padrao
	printf("%p\n", &a); // escreve o endereco de 'a' na saida padrao

	int b; // reserva um (outro) bloco de 4 bytes na memoria

	printf("%p\n", &b);

 	int c, d; // declara mais 2 variaveis inteiras

	//printf("%p\n%p\n", &c, &d);
	
	printf("%p\n", &c);
	printf("%p\n", &d);

	return 0; // significa que finalizou com nenhum erro (0)
}
