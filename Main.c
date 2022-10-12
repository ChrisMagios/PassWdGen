#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sodium.h>

char passWd[] = "";

void print_banner(void) {
	printf("______             _    _     _ _____\n");
	printf("| ___ \\           | |  | |   | |  __ \\\n");
	printf("| |_/ /_ _ ___ ___| |  | | __| | |  \\/ ___ _ __\n");
	printf("|  __/ _` / __/ __| |/\\| |/ _` | | __ / _ \\ '_ \\\n");
	printf("| | | (_| \\__ \\__ \\  /\\  / (_| | |_\\ \\  __/ | | |\n");
	printf("\\_|  \\__,_|___/___/\\/  \\/ \\__,_|\\____/\\___|_| |_|\n\n");
}

int main() {
	print_banner();
	srand(time(0));

	int length = rand() % (30 - 15 + 1) + 25;

	if (sodium_init() == -1) {
		printf("Failed to initialize Sodium...");
		return 1;
	}

	for (int i = 0; i < length; i++) {
		passWd[i] = rand() % (93) + 33;
	}
	printf("%s\n\n", &passWd);

	sodium_memzero(&passWd, length);
	puts("Press <enter> to quit...");
	getchar();
	
	return 0;
}

                                               