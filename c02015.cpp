#include <stdio.h>

int main() {
	int h;
	scanf("%d", &h);
	
	for (int i = 0; i < h; i++) {
		for (int j = 1; j <= 2 * i + 1; j++) {
			printf("%d", j);
		}
		printf("\n");
	}
	return 0;
}
