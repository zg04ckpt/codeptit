#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int p[] = {2, 3, 5, 7};

int check(int n) {
	for (int i = 0; i < 4; i++) {
		if (n == p[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	char c[11];
	gets(c);
	int n = strlen(c);

	for (int i = 0; i < n; i++) {
		if(check(c[i] - '0')) {
			int count = 1;
			for (int j = i + 1; j < n; j++) {
				if (c[j] == c[i]) {
					count++;
					c[j] = '\0';
				} 
			}
			printf("%c %d\n", c[i], count);
		}
	}
	return 0;
}
