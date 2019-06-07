#include <stdio.h>
#include <unistd.h>

int main(){
	int duration = 15 * 1000 * 1000;

	printf("usleep(%d)\n", duration);
	usleep(duration);

	return 0;
}
