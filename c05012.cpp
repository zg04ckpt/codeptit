#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	
	for (int k = 1; k <= t; k++) {
		int m;
		scanf("%d", &m);
		int A[m][m], T[m][m], Re[m][m];
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (j > i) {
					A[i][j] = 0;
				} else {
					A[i][j] = j + 1;
				}
				T[j][i] = A[i][j];
			}
		}
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				Re[i][j] = 0;
				for (int k = 0; k < m; k++) {
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
