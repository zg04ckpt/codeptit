#include <stdio.h>
#include<string.h>
#include <stdbool.h>

void chuyen_doi(char s[], int n, int num[]) {
	for (int i = 0; i < n; i++) {
		num[i] = s[i] - '0';
	}
}

void phan_tach(int arr[], int a[], int b[], int start, int end, int size_a) {
	int count_a = 0;
	int count_b = 0;
	for (int i = start; i < end; i++) {
		if (i < start + size_a) {
			a[count_a] = arr[i];
			count_a++;
		} else {
			b[count_b] = arr[i];
			count_b++;
		}
	}
}

int cong(int arr1[], int a[], int b[], int end, int size_a, int size_b) {
	
	int size = size_b + 1;
	int a1[size], b1[size];
	a1[0] = 0;
	b1[0] = 0;
	
	int count_a = 0;
	int count_b = 0;
	if (size_b != size_a) {
		a1[1] = 0;
		for (int i = 1; i < size; i++) {
			if (i >= 2) {
				a1[i] = a[count_a];
				count_a++;
			}
			b1[i] = b[count_b];
			count_b++;
		}	
	} else {
		for (int i = 1; i < size; i++) {
			a1[i] = a[count_a];
			b1[i] = b[count_b];
			count_a++;
			count_b++;
		}	
	}
	
	int memo = 0, i, j;
	for (i = end - 1, j = size - 1; i >= (end - size), j >= 0; i--, j--) {
		arr1[i] = a1[j] + b1[j] + memo;
		memo = arr1[i] / 10;
		arr1[i] = arr1[i] % 10;
	}
	
	if (arr1[end - size] == 0) {
		return size - 1;
	}
	return size;
}

int main() {
	
	char s[201];
	gets(s);
	int n = strlen(s);
	int arr[n], m = n, number;
	double check;
	chuyen_doi(s, n, arr);
	
	int size_a;
	int size_b;
	while(1) {
		check = m / 2.0;
		if ((check - (int)check) != 0) {
			size_b = (int)check + 1;
		} else {
			size_b = (int)check;
		}
		
		size_a = m - size_b;
		int b[size_b];
		int a[size_a];
		
		phan_tach(arr, a, b, n - m, n, size_a);
		m = cong(arr, a, b, n, size_a, size_b);
		
		for (int i = n - m; i < n; i++) {
			printf("%d", arr[i]);
		}
		printf("\n");
		
		if (m == 1) {
			break;
		}
	}

	return 0;
}
