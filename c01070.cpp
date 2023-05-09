#include <stdio.h>
#include <math.h>

// a + d == check || b + c == check || b + d == check

int checkHV(int idx, int a[], int b[], int c[]) {
	int check = a[idx];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (b[i] + c[j] == check) {
				if (b[1-i] == c[1-j] && a[1-idx] + b[1-i] == check) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	int a[2], b[2], c[2], max = -1;
	char d[2];
	for (int i = 0; i < 2; i++) {
		scanf("%d", &a[i]);
		if (a[i] > max) {
			max = a[i];
			d[1] = i;
			d[0] = 'a';
		}
	}
	for (int i = 0; i < 2; i++) {
		scanf("%d", &b[i]);
		if (b[i] > max) {
			max = b[i];
			d[1] = i;
			d[0] = 'b';
		}
	}
	for (int i = 0; i < 2; i++) {
		scanf("%d", &c[i]);
		if (c[i] > max) {
			max = c[i];
			d[1] = i;
			d[0] = 'c';
		}
	}
	
	if (d[0] == 'a') {
		if (checkHV(d[1], a, b, c)) {
			printf("YES");
		} else {
			printf("NO");
		}
	} else if (d[0] == 'b') {
		if (checkHV(d[1], b, a, c)) {
			printf("YES");
		} else {
			printf("NO");
		}
	} else {
		if (checkHV(d[1], c, a, b)) {
			printf("YES");
		} else {
			printf("NO");
		}
	}
}
