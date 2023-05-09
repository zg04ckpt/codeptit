#include <stdio.h>

int main() {
	int num = 0, N;
	scanf("%d", &N);
	getchar();
	char A[N][N];
	int a[N][N], maxi = 0, maxj = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = getchar();
			a[i][j] = A[i][j] - '0';
		}
		getchar();
	}
	
	for (int i = N-1; i >= 0; i--) {
		for (int j = N-1; j >= 0; j--) {
			if (a[i][j] == 1) {
				for (int p = 0; p <= i; p++) {
					for (int q = 0; q <= j; q++) {
						a[p][q] = 1 - a[p][q];
					}
				}
				num++;
			}
		}
	}
	
	printf("%d", num);
	
}
	


