#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	
	long A, B;
	scanf("%ld%ld", &A, &B);
	t--;
	while(t--) {
		long a, b;
		scanf("%ld%ld", &a, &b);
		A = (a < A)? a:A;
		B = (b < B)? b:B;
	}

	printf("%lld", A*B);
}
