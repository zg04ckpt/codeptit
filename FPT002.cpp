#include <stdio.h>

int main() {
	int m, n, p, q;
	scanf("%d %d %d %d", &m, &n, &p, &q);
	int A[m][n], B[n][p], C[p][q];
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			scanf("%d", &B[i][j]);
		}
	}
	
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < q; j++) {
			scanf("%d", &C[i][j]);
		}
	}
	
	//nhân lần 1
	int AB[m][p];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < p; j++) {
			AB[i][j] = 0;
			for (int k = 0; k < n; k++) {
				AB[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	
	//nhân lần 2 D = ABC
	int ABC[m][q];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < q; j++) {
			ABC[i][j] = 0;
			for (int k = 0; k < p; k++) {
				ABC[i][j] += AB[i][k] * C[k][j];
			}
		}
	}
	
	//in ma trận
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < q; j++) {
			printf("%d ", ABC[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
