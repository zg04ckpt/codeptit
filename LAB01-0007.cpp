#include <stdio.h>

int main() {
	int n; 
	scanf("%d", &n);
	int a[n];
	double avg = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		avg += a[i];
	}
	
	printf("%.3f", avg / n);
	
	return 0;
}
