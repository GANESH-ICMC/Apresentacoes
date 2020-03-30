#include <stdio.h>



int main(void) {


	

	char c;  // caracter, ocupa 1 byte

	int a;   // inteiro, ocupa 4 bytes	

	float b; // real com precisao limitada, ocupa 4 bytes	

	
double d;   // real com precisao limitada, ocupa 8 bytes

	long int e; // inteiro com 8 bytes




	a = 2000000000; 

	b = 5.1023981;
	

	d = 1023.81384183413;

	e = 50000000000;


	c = 'x';

	

printf("%c (%p)\n", c, &c);  // c de caracter (p para enderecos)

	printf("%d (%p)\n", a, &a);  // d de decimal
	
	printf("%f (%p)\n", b, &b);  // f de float

	printf("%lf (%p)\n", d, &d); // lf como se fosse 'long float'

	printf("%ld (%p)\n", e, &e); // ld long decimal


	printf("char = %ld\n", sizeof(char)); 

	printf("int = %ld\n", sizeof(int)); 

	printf("float = %ld\n", sizeof(float)); 

	printf("double = %ld\n", sizeof(double)); 

	printf("long int = %ld\n", sizeof(long int));

 


	return 0;
}


