#include <stdio.h>

int check(int n) {
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return n > 1;
}

int main() {
	int m;
	scanf("%d", &m);
	
	int a[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	int count = 0, max = 0, flag = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (check(a[i][j])) {
				count++;
			}
		}
		
		if (max < count) {
			max = count;
			flag = i;
		}
		count = 0;
	}
	
	printf("%d\n", flag + 1);
	for (int j = 0; j < m; j++) {
		if (check(a[flag][j])) {
			printf("%d ", a[flag][j]);
		}
	}
}
