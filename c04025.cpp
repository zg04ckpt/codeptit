#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[n];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);	
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			printf("%d ", arr[i]);	
		}
	}
	
	//số âm chia dư 2 có TH bằng -1
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1 || arr[i] % 2 == -1) {
			printf("%d ", arr[i]);	
		}
	}
}