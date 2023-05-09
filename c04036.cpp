#include <stdio.h>

int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main() {
	
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int n, count = 0, i = 9;
		scanf("%d", &n);
		while(i >= 0 && n > 0) {
			if(n - a[i] >= 0) {
				n -= a[i];
				count++;
			} else {
				i--;
			}
		}
		printf("%d\n", count);
	}
}
