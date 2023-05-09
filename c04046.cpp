#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int*)a > *(int*)b;
}

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int n;
		scanf("%d", &n);
		
		int a[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		
		qsort(a, n, sizeof(int), cmp);
//		for (int i = 0; i < n; i++) {
//			printf("%d ", a[i]);
//		}
		
		int kc[n-1], min = a[1]-a[0];
		for (int i = 1; i < n; i++) {
			kc[i-1] = a[i] - a[i-1];
			if (kc[i-1] < min) {
				min = kc[i-1];
			}
		}
		
		int count = 0;
		for (int i = 0; i < n-1; i++) {
			if (kc[i] == min) {
				count++;
			}
		}
		
		printf("%d %d\n", min, count);
	}
}
