#include <stdio.h>
#include <string.h>

//I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000;

void convert(char s[], int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (s[i] == 'I') {
			a[i] = 1;
		} else if (s[i] == 'V') {
			a[i] = 5;
		} else if (s[i] == 'X') {
			a[i] = 10;
		} else if (s[i] == 'L') {
			a[i] = 50;
		} else if (s[i] == 'C') {
			a[i] = 100;
		} else if (s[i] == 'D') {
			a[i] = 500;
		} else {
			a[i] = 1000;
		}
	}
}

int calc(int a[], int n) {
	int sub = a[0], SUM = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			sub += a[i];
		} else if (a[i] < a[i-1]) {
			SUM += sub;
			sub = a[i];
		} else {
			SUM -= sub;
			sub = a[i];
		}
	}
	SUM += sub;
	
	return SUM;
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	
	while(t--) {
		char s[50];
		gets(s);
		int n = strlen(s);
		int a[n];
		convert(s, a, n);
		printf("%d\n", calc(a, n));
	}
}
