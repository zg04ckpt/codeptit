#include <stdio.h>

int main() {
	int h;
	scanf("%d", &h);
	
	for (int i = 1; i <= h; i++) {
		if (i == 1) {
			printf("%d ", 1);
		}
		int c = 1, k = 0;
		for (int j = i; c <= i && i != 1; j += h - k) {
			printf("%d ", j);
			k++;
			c++;
		}
		printf("\n");
	}
	return 0;
}
