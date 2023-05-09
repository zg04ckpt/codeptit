#include <stdio.h>

void sortArr(int arr[], int n) {
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

void show(int arr[], int n, int k) {
	printf("Buoc %d: ", k);	
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);	
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n], printArr[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);	
	}
	
	for (int i = 0; i < n; i++) {
		printArr[i] = arr[i];
		sortArr(printArr, i + 1);
		show(printArr, i + 1, i);
		printf("\n");
	}
}