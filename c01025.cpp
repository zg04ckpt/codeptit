#include <stdio.h>

int main() {
	int x[4], y[4];
	for (int i = 0; i < 4; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	
	int max = x[0], min = x[0];
	for (int i = 1; i < 4; i++) {
		max = (max < x[i])? x[i]:max;
		min = (min > x[i])? x[i]:min;
	}
	int len_x = max - min;
	
	max = y[0],
	min = y[0];
	for (int i = 1; i < 4; i++) {
		max = (max < y[i])? y[i]:max;
		min = (min > y[i])? y[i]:min;
	}
	int len_y = max - min;
	
	int res = (len_x > len_y)? len_x:len_y;
	printf("%d", res*res);
}
