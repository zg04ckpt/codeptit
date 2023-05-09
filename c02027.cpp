#include <stdio.h>

int main() {
	int h;
	scanf("%d", &h);
	
	char max = 'a' - 1, min = 'a' - 1;
	for (int i = 1; i <= h; i++) {
		min = max + 1;
		max += i;
		if (i % 2 == 1) {
			for (int j = min; j <= max; j++) {
				printf("%c ", j);
			}
		} else {
			for (int j = max; j >= min; j--) {
				printf("%c ", j);
			}
		}
		printf("\n");
	}
	return 0;
}
