#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int t;
	scanf("%d", &t);
	
	for (int k = 1; k <= t; k++) {
		int m, n;
		scanf("%d%d", &m, &n);
		int a[m][n];
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		
		/*
			tại mỗi phần tử của mảng, tiến hành sắp xếp từ hàng và cột chứa điểm đó đến điểm cuối
			ví dụ tại ptu (0,1) của mảng 3x3 thì duyệt 	01 01
														11 12
													   	21 22
		*/
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				for (int p = i; p < m; p++) {
					for (int q = j ; q < n; q++) {
						if (a[i][j] > a[p][q]) {
							swap(&a[i][j], &a[p][q]);
						}
					}
				}
			}
		}
		
		printf("Test %d:\n", k);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}
