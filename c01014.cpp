#include <stdio.h>

void create(int a[], int len, int n) {
	for (int i = 0; i < len; i++) {
		a[i] = n;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	
	int len = 2 * n - 1;
	int A[len];
	create(A, len, n + 1);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len; j++) {
			if (j >= i && j <= len - 1 - i) {
				A[j] -= 1;
			}
		}
		for (int j = 0; j < len; j++) {
			printf("%d", A[j]);
		}
		printf("\n");
	}
	
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j < len; j++) {
			if (j >= i && j <= len - 1 - i) {
				A[j] += 1;
			}
		}
		for (int j = 0; j < len; j++) {
			printf("%d", A[j]);
		}
		printf("\n");
	}
	
	return 0;
}
