#include <stdio.h>

int check(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return n > 1;
}

int main() {
	int m;
	scanf("%d", &m);
	
	int A[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	
	int sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			if (check(A[i][j])) {
				sum += A[i][j];
			}
		}
	}
	printf("%d", sum);
}
