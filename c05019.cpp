#include <stdio.h>

int arr[1000001];
int prime[100000];

void seive() {
	for (int i = 1; i <= 1000000; i++) {
		arr[i] = 1;
	}
	
	arr[0] = arr[1] = 0;
	for (int i = 2; i*i <= 1000000; i++) {
		if (arr[i]) {
			for (int j = i*i; j <= 1000000; j += i) {
				arr[j] = 0;
			}
		}
	}
	
	int count = 1;
	for (int i = 1; i <= 1000000; i++) {
		if (arr[i]) {
			prime[count++] = i;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	
	seive();
	for (int k = 1; k <= t; k++) {
		int m;
		scanf("%d", &m);
		
		int a[m][m];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = 0;
			}
		}
		
		int max = m*m, x = 0, y = 0, dx = 0, dy = 1, count = 1;
		while(count <= max) {
			
			if (x + dx == m || y + dy == m || x + dx < 0 || y + dy < 0 || a[x + dx][y + dy] != 0) {
				int temp = dx;
				dx = dy;
				dy = -temp;
			}
			
			a[x][y] = prime[count++];
			
			x += dx;
			y += dy;
		}
		
		printf("Test %d: \n", k);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}
