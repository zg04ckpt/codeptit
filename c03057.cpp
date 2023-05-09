#include<stdio.h> 
#include <string.h>

long convertMax(long X) {
	int arr[19], i = 0;
	long max = 0;
	while (X > 0) {	
		arr[i] = X % 10;
		i++;
		X /= 10;
	}
	for (int j = i - 1; j >= 0; j--) {
		if (arr[j] == 5) {
			arr[j]++;
		}
		max += arr[j];
		if (j != 0) {
			max *= 10;
		}
	}
	return max;
}

long convertMin(long X) {
	int arr[19], i = 0;
	long min = 0;
	while (X > 0) {	
		arr[i] = X % 10;
		i++;
		X /= 10;
	}
	for (int j = i - 1; j >= 0; j--) {
		if (arr[j] == 6) {
			arr[j]--;
		}
		min += arr[j];
		if (j != 0) {
			min *= 10;
		}
	}
	return min;
}

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--) {
		long X1, X2, max, min;
		scanf("%ld %ld", &X1, &X2);
		
		max = convertMax(X1) + convertMax(X2);
		min = convertMin(X1) + convertMin(X2);
		printf("%ld %ld\n", min, max);
	}
}