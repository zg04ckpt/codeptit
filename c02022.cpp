#include <stdio.h>

int main() {
	int h;
	scanf("%d", &h);
	
	int max = 0, min = 0;
	for (int i = 1; i <= h; i++) {
		min = max + 1;
		max += i;
		if (i % 2 == 1) {
			for (int j = min; j <= max; j++) {
				printf("%d ", j);
			}
		} else {
			for (int j = max; j >= min; j--) {
				printf("%d ", j);
			}
		}
		printf("\n");
	}
	return 0;
}
