#include <stdio.h>
#include <math.h>

int A[2000000];

void sang_nto() {
	for (int i = 1; i <= 2000000; i++) {
		A[i] = i;
	}
	
	A[1] = 1;
	for (int i = 2; i <= 2000000; i += 2) {
		A[i] = 2;
	}
	
	for (int i = 3; i <= sqrt(2000000); i += 2) {
		if (A[i] == i) {
			for (int j = i * i; j <= 2000000; j += i) {
				A[j] = i;
			}
		}
	}
}

int main() {
	sang_nto();
	int t, n;
	scanf("%d", &t);
	
	long long sum = 0;
	while(t--) {
		scanf("%d", &n);
		while (n > 1) {
			sum += A[n];
			n /= A[n];
		}
	}
	printf("%lld", sum);
	return 0;
}