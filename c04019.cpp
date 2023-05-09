#include <stdio.h>
#include <stdbool.h>

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int n;
		scanf("%d", &n);
		int arr[n], count[n], max = 0;
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			count[i] = 1;	
		}
		
		for (int i = 0; i < n; i++) {
			if (count[i] == NULL) continue;
			for (int j = i + 1; j < n; j++) {
				if (arr[i] == arr[j] && count[j] != NULL) {
					count[i]++;
					count[j] = NULL;
				}
			}
			if (count[i] > max) {
				max = count[i];
			}
		}
		
		for (int i = 0; i < n; i++) {
			if (count[i] == max) {
				printf("%d ", arr[i]);
			}	
		}
		printf("\n");
	}
}