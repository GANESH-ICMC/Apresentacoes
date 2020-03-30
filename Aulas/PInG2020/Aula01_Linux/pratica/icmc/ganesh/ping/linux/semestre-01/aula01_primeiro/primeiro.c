// Primeiro programa de ICC1 em linguagem C
// Moacir A. Ponti, Marco de 2019

#include <stdio.h>

int main(void) {

	// comentario - apenas para documentar, ignorado pelo compilador

	int a;  // aloca um espaco para um numero inteiro (int)
	a = 50; // armazena o valor 50 nessa posicao

	int b;     // aloca um espaco para um numero inteiro (int)
	b = a + 1; // recupera o valor em 'a' e soma 1, armazena em 'b'

	printf("Valores: \n");
	printf("%d\n", a);
	printf("%d\n", b);
	
	printf("Enderecos: \n");
	printf("%p\n", &a); // operador & extrai o endereco na memoria
	printf("%p\n", &b);
	
	return 0;
}
