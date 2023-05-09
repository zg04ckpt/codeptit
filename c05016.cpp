#include <stdio.h>

int main() {
	int m;
	scanf("%d", &m);
	
	int a[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = 0;
		}
	}
	
	/*
	đi ngang sang phải dx = 0; dy = 1;
	đi dọc xuống dưới dx = 1; dy = 0;
	đi ngang sang trái dx = 0; dy = -1;
	đi dọc lên trên dx = -1; dy = 0;
	=> mỗi lần chuyển hướng dy = -dx, dx = dy
	chuyển hướng khi x, y bằng m hoặc gặp vị trí khác 0
	*/
	int max = m*m, x = 0, y = 0, dx = 0, dy = 1, count = 1;
	while(count <= max) {
		
		if (x + dx == m || y + dy == m || x + dx < 0 || y + dy < 0 || a[x + dx][y + dy] != 0) {
			int temp = dx;
			dx = dy;
			dy = -temp;
		}
		
		a[x][y] = count++;
		
		x += dx;
		y += dy;
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
