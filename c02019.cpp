#include <stdio.h>

int main() {
	int h;
	scanf("%d", &h);
	
	for (int i = 0; i < h; i++) {
		for (int j = 1; j <= h - i - 1; j++) {
			printf("~");
		}
		for (int j = 2; j <= 2 * i + 2; j += 2) {
			printf("%d", j);
		}
		for (int j = 2 * i; j >= 2; j -= 2) {
			printf("%d", j);
		}
		printf("\n");
	}
	return 0;
}
