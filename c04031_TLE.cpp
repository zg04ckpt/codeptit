#include <stdio.h>

int main() {
	int t, c = 1;
	scanf("%d", &t);
	
	while(c <= t) {
		int n, count = 1, max = 1;
		scanf("%d", &n);
		int a[n], flag[n];
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);	
		}
		
		flag[0] = 1;
		for (int i = 1; i < n; i++) {
			if (a[i] <= a[i - 1]) {
				max = (max < count)? count:max;
				count = 1;
			} else {
				count++;
			}
			flag[i] = count;
		}
		
		printf("Test %d: \n%d\n", c, max);
		for (int i = 0; i < n; i++) {
			if (flag[i] == max) {
				for (int j = i + 1 - max; j <= i; j++) {
					printf("%d ", a[j]);
				}
				printf("\n");
			}
		}
	}
}