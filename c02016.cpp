#include <stdio.h>

int main() {
	int h;
	scanf("%d", &h);
	
	for (int i = 0; i < h; i++) {
		if ((i + 1) % 2 == 1) {
			for (int j = 1; j <= 2 * i + 2; j += 2) {
				printf("%d", j);
			}
		} else {
			for (int j = 2; j <= 2 * i + 2; j += 2) {
				printf("%d", j);
			}
		}
		
		printf("\n");
	}
	return 0;
}
