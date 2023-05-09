#include <stdio.h>

void sortASC(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}	
	}
}

void sortDESC(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}	
	}
}

void show(int arr[], int n, int k) {
	printf("Test %d: \n", k);	
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);	
	}
	printf("\n");
}

int main() {
	int t, count = 1;
	scanf("%d", &t);
	
	while(count <= t) {
		int n;
		scanf("%d", &n);
		int a[n], b[n], res[2 * n];
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);	
		}
		sortASC(a, n);
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);	
		}
		sortDESC(b, n);
		
		int c1 = 0, c2 = 0;
		for(int i = 0; i < 2 * n; i++) {
			if (i % 2 == 0) {
				res[i] = a[c1++];
			} else {
				res[i] = b[c2++];
			}
		}
		
		show(res, 2 * n, count++);
	}
}


