#include <stdio.h>

long long fibo[82];

void init() {
	fibo[1] = 0;
	fibo[2] = 1;
	for (int i = 3; i < 82; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
}

int main() {
	init();
	int m;
	scanf("%d", &m);
	
	long long a[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = -1;
		}
	}
	
	int max = m*m, x = 0, y = 0, dx = 0, dy = 1, count = 1;
	while(count <= max) {
		
		if (x + dx == m || y + dy == m || x + dx < 0 || y + dy < 0 || a[x + dx][y + dy] != -1) {
			int temp = dx;
			dx = dy;
			dy = -temp;
		}
		
		a[x][y] = fibo[count++];
		
		x += dx;
		y += dy;
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%lld ", a[i][j]);
		}
		printf("\n");
	}
}
