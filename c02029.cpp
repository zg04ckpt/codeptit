#include <stdio.h>

int main() {
	int h;
	scanf("%d", &h);
	
	for (int i = 1; i <= h; i++) {
		if (i == 1) {
			printf("%c ", 'A');
		}
		int c = 1, k = 0;
		for (char j = 'A' + i - 1; c <= i && i != 1; j += h - k) {
			printf("%c ", j);
			k++;
			c++;
		}
		printf("\n");
	}
	return 0;
}
