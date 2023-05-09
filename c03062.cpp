#include <stdio.h>

long int gcd(long int a, long int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

long int lcm(long int a, long int b) {
	return a*b / gcd(a, b);
}

int main() {
	long int t;
	scanf("%d", &t);
	
	while(t--) {
		long int a, b;
		scanf("%ld%ld", &a, &b);
		
		long int A[b-a+1];
		
		long int n = 0;
		for (long int i = a; i <= b; i++) {
			A[n] = i;
			n++;
		}
		
		long int bc = 1;
		for (long int i = 0; i < n; i++) {
			bc = lcm(bc, A[i]);
		}
	
		printf("%ld\n", bc);
	}
}
