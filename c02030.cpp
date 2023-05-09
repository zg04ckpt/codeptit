#include <stdio.h>

int main() {
	int h;
	scanf("%d", &h);
	
	for (int i = 1; i <= h; i++) {
		char c = 'B';
		for (int j = 1; j <= 2 * i - 1; j++) {
			if (j == 1 || j == 2 * i - 1) {
				printf("@");
			} else if (j < i) {
				printf("%c", c);
				c += 2;
			} else if (j == i) {
				printf("%c", c);
			} else {
				c -= 2;
				printf("%c", c);
			}
		}
		printf("\n");
	}
	return 0;
}
