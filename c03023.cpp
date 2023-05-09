#include <stdio.h>
#include <stdbool.h>

bool checkTN9(int n) {
	int have9 = 0;
	int m = n, k = 0;
	while (m > 0) {
		if (m % 10 == 9) {
			have9 = 1;
		}
		k += m % 10;
		m /= 10;
		if (m > 0) {
			k *= 10;
		}
	}
	if (k == n && have9 == 0) {
		return true;
	}
	return false;
}

int main() {
	int n, count = 0;
	scanf("%d", &n);
	
	for (int i = 2; i < n; i++) {
		if (checkTN9(i)) {
			printf("%d ", i);
			count++;
		}
	}
	printf("\n%d", count);
	return 0;
}
