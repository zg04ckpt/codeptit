#include <stdio.h>

int main() {
	int n; 
	scanf("%d", &n);
	int A[n][n], count = 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) {
				A[i][j] = j - i;
			} else {
				A[i][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}
