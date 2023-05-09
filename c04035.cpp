#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return *(int*)a - *(int*)b;
}

int swap(int * a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int n, time = 0;
	scanf("%d", &n);
	
	int up[n], down[n];
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &up[i], &down[i]);
		time += up[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (down[i] > down[j]) {
				swap(&up[i], &up[j]);
				swap(&down[i], &down[j]);
			}
		}
	}
	
//	for (int i = 0; i < n; i++) {
//		printf("%d %d\n", up[i], down[i]);
//	}
	
	int extra = 0;
	for (int i = 0; i < n; i++) {
		if (up[i] == 0) {
			continue;
		}
		
		int j;
		for (j = i + 1; j < n; j++) {
			if (down[i] <= up[j]) {
				break;
			}
		}
		
		int a = down[i] - up[j];
		if (a > 0) {
			extra += a;
		}
		up[j] = 0;
	}

	printf("%d", time + extra);
	
}
