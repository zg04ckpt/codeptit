#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int n;
		scanf("%d", &n);
		int a[n], b[n], count = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (a[i] >= 0) {
				b[count++] = i;
			}
		}
		
		int sum = 0, max = a[0];
		for(int i = 0; i < count; i++) {
			for(int j = i; j < count; j++) {
				for (int k = b[i]; k <= b[j]; k++) {
					sum += a[k];
				}
				if (sum > max) max = sum;
				sum = 0;
			}
		}
		
		printf("%d\n", max);
	}
}
