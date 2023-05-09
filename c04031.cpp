#include <stdio.h>

int main() {
	int t, num_t;
	scanf("%d", &t);
	
	int b[100], i;
	for(i = 0; i < 100; i++) {
		b[i] = 1;
	}
	
	int a[100], n, j;
	for(num_t = 1; num_t <= t; num_t++) {
		
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		
		for(i = 0; i < n - 1; i++) {
			for (j = i + 1; a[j] > a[j - 1]; j++) {
				b[j] = b[j - 1] + 1;
			}
			i = j - 1;
			j = 0;
		}
		
		int max = 1;
		for(i = 0; i < n; i++) {
			if (max < b[i]) {
				max = b[i];
			}
		}
		
		printf("Test %d: \n%d \n", num_t, max);
		for(i = max - 1; i < n; i++) {
			if (max == b[i]) {
				for(j = i + 1 - max; j <= i; j++) {
					printf("%d ", a[j]);
				}
				printf("\n");
			}
		}
	}
}