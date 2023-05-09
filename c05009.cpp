#include <stdio.h>

int main() {
	int m;
	scanf("%d", &m);
	
	int A[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) {
				int temp = A[i][j];
				A[i][j] = A[i][m - 1 - j];
				A[i][m - 1 - j] = temp;
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}
