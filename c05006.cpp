#include <stdio.h>

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int A[m][n];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	
	int a, b;
	scanf("%d%d", &a, &b);
	
	for (int j = 0; j < n; j++) {
		int temp = A[a - 1][j];
		A[a - 1][j] = A[b - 1][j];
		A[b - 1][j] = temp;
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}
