#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	
	for (int k = 1; k <= t; k++) {
		int m;
		scanf("%d", &m);
		
		int a[m][m];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = 0;
			}
		}
		
		int x = 0, y = 0, dx = 0, dy = 1, count = m*m;
		while(count >= 1) {
			
			if (x + dx == m || y + dy == m || x + dx < 0 || y + dy < 0 || a[x + dx][y + dy] != 0) {
				int temp = dx;
				dx = dy;
				dy = -temp;
			}
			
			a[x][y] = count--;
			
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