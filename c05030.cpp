#include <stdio.h>
#include <stdlib.h>

typedef struct DiemAnh{
	int val;
	int i;
	int j;
} DA;

int cmp(const void *a, const void *b) {
	DA *da1 = (DA*)a;
	DA *da2 = (DA*)b;
	return da1->val - da2->val;
}

int main() {
	int t, count = 0;
	scanf("%d", &t);
	getchar();
	
	while(t--) {
		int m, n;
		scanf("%d%d", &m, &n);
		getchar();
		
		DA da1[m*n], da2[m*n];
		int c1 = 0, c2 = 0;
		
		int a[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = getchar() - '0';
			}
			getchar();
		}
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] != 0) {
					if (a[i][j] == 1) {
						da1[c1].val = a[i][j];
						da1[c1].i = i;
						da1[c1].j = j;
						c1++;
					} else {
						da2[c2].val = a[i][j];
						da2[c2].i = i;
						da2[c2].j = j;
						c2++;
					}
				}
			}
		}
		
//		qsort(da, c1, sizeof(DA), cmp);
		
		for (int i = 0; i < c1; i++) {
			for (int j = i+1; j < c1; j++) {
				if (da1[j].i != da1[i].i && da1[j].j != da1[i].j) {
					for (int k = 0; k < c2; k++) {
						if(da2[k].i == da1[i].i && da2[k].j == da1[j].j) {
							count++;
						}
					}
				}
			}
		}
		
		for (int i = 0; i < c2; i++) {
			for (int j = i+1; j < c2; j++) {
				if (da2[j].i != da2[i].i && da2[j].j != da2[i].j) {
					for (int k = 0; k < c1; k++) {
						if(da1[k].i == da2[i].i && da1[k].j == da2[j].j) {
							count++;
						}
					}
				}
			}
		}
		
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				printf("%d ", a[i][j]);
//			}
//			printf("\n");
//		}
	}
	
	printf("%d", count);
}