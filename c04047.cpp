#include <stdio.h>

void sortArray(int a[], int b[], int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
}

int main() {
	int n, time = 0;
	scanf("%d", &n);
	int a[n], b[n]; // mảng a thời gian đến, mảng b thời gian làm thủ tục
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
	}
	
	sortArray(a, b, n);
	
	time += a[0] + b[0];
	for (int i = 1; i < n; i++) {
		if (a[i] <= time) {
			time += b[i];
		} else {
			time = a[i] + b[i];
		}
	}
	printf("%d", time);
}
