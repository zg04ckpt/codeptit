#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int m, n;
		scanf("%d%d", &n, &m);
		
		long a[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%ld", &a[i][j]);
			}
		}
		
		long b[m*n], count = m*n, countb = 0;
		int x = 0, y = 0;
		int dx = 0, dy = 1;
		while(count--) {
			if (x+dx == n || y+dy == m || x+dx < 0 || y+dy < 0 || a[x+dx][y+dy] == -999999) {
				int temp = dx;
				dx = dy;
				dy = -temp;
			}
			
			b[countb++] = a[x][y];
			a[x][y] = -999999;
			
			x += dx;
			y += dy;
		}
		
		for (int i = 0; i < m*n; i++) {
			printf("%ld ", b[i]);
		}
		printf("\n");
	}
}
