#include <stdio.h>

int main() {
	int n, count = 1;
	scanf("%d", &n);
	int arr[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);	
	}
	
	for (int i = 0; i < n - 1; i++) {
		int min_id = i;
		
		for (int j = i + 1; j < n; j++) {	
			if (arr[j] < arr[min_id]) {
				min_id = j;
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[min_id];
		arr[min_id] = temp;
		
		printf("Buoc %d: ", count++);
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
}