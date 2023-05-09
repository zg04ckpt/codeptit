#include <stdio.h>

int main() {
	int t, k = 1;
	scanf("%d", &t);
	while(k <= t) {
		int m, n, sum = 0;
		scanf("%d%d", &m, &n);
		int A[m][n];
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &A[i][j]);
			}
		}
		
		int max = 0, flag[2];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				sum += A[i][j];
			}
//			printf("i = %d, sum = %d\n", i, sum);
			if (sum > max) {
				max = sum;
				flag[0] = i;
			}
			sum = 0;
		}
//		printf("flag_i = %d\n", flag[0]);
		
		max = 0;
		sum = 0;
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < m; i++) {
				if (i != flag[0]) {
					sum += A[i][j];
				}
			}
//			printf("j = %d, sum = %d\n", j, sum);
			if (sum > max) {
				max = sum;
				flag[1] = j;
			}
			sum = 0;
		}
//		printf("flag_j = %d\n", flag[1]);
		
		printf("Test %d:\n", k++);
		for (int i = 0; i < m; i++) {
			if (i != flag[0]) {
				for (int j = 0; j < n; j++) {
					if (j != flag[1]) {
						printf("%d ", A[i][j]);
					}
				}
				printf("\n");
			}
			
		}
	}
}
