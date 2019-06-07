#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv, char **env) {
	char* LD_PROT = getenv("LD_PRELOAD");

	if(LD_PROT != NULL) {
		printf("kkk não vai dar LD_PRELOAD no meu código não\n");
		exit(1);
	}

	srand(time(NULL));
	for(int i = 0; i < 10; i++)
		printf("%d\n", rand());

	return 0;
}
