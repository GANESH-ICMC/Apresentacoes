#include <stdio.h>
#include <stdlib.h>

int main (void) {

	// sequencia de Fibonacci
	int N = 8; // hard coded (depois pode trocar por scanf)

	int n_1 = 1, n_2 = 1;

	int atual = 1;
	int num = 0;
	while (atual <= N) {
		if (atual == 1 || atual == 2) {
			num = 1;
		}
		else {
			num = n_1 + n_2;

			// para a proxima vez
			// n-2 passa a ser n-1
			// n-1 passa a ser o numero atual
			n_2 = n_1;
			n_1 = num;
		}	
		printf("f(%d) = %d\n", atual, num);
		atual = atual + 1;
	}	
	
	return 0;
}
