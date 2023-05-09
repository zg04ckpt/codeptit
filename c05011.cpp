#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	
	for (int k = 1; k <= t; k++) {
		int m, n;
		scanf("%d%d", &m, &n);
		int A[m][n], T[n][m], Re[m][m];
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &A[i][j]);
				T[j][i] = A[i][j];
			}
		}
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				Re[i][j] = 0;
				for (int k = 0; k < n; k++) {
					Re[i][j] += A[i][k] * T[k][j];
				}
			}
		}
		
		printf("Test %d:\n", k);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", Re[i][j]);
			}
			printf("\n");
		}
	}
}
