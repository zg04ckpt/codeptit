#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	int check = 1, count = 1;
	while(check) {
		check = 0;
		for (int i = 0; i < n-1; i++) {
			if (a[i] > a[i+1]) {
				check = 1;
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
		if (check == 1) {
			printf("Buoc %d: ", count++);
			for (int i = 0; i < n; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
		}
	}
}
