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
	
	for (int j = 0; j < m; j++) {
		int temp = A[j][a - 1];
		A[j][a - 1] = A[j][b - 1];
		A[j][b - 1] = temp;
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}
