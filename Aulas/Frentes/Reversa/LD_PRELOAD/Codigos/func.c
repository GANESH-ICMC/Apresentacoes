#define _GNU_SOURCE

#include <stdio.h>
#include <dlfcn.h>

int rand() {
	int (*orig_rand)(void);
	orig_rand = dlsym(RTLD_NEXT, "rand");
	int val = (*orig_rand)();

	printf("rand retornou %d\n", val);
	return val;
}
