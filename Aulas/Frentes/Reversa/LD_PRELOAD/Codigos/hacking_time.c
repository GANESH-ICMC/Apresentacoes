#include <stdio.h>

unsigned int usleep(unsigned int microseconds) {
	printf("usleep(%u)\n", microseconds);
	return 0;
}
