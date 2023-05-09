#include <stdio.h>

int main() {
	int n, count = 1;
	scanf("%d", &n);
	int arr[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);	
	}
	
	for (int i = 0; i < n; i++) {
		int isSorted = 0;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				isSorted = 1;
			}
		}
		if (isSorted) {
			printf("Buoc %d: ", count++);
			for (int i = 0; i < n; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}
	}
}