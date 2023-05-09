#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int lcm(int a, int b) {
	return a*b / gcd(a, b);
}

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int n;
		scanf("%d", &n);
		
		int a[n];
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		
		// tạo mảng b với số đầu và cuối giống a
		int b[n+1];
		b[0] = a[0];
		b[n] = a[n-1];
		// để tổng min thì b[i] phải là bcnn của a[i-1] và a[i]
		for (int i = 1; i < n; i++) {
			b[i] = lcm(a[i], a[i-1]);
		}
		
		// in ra mh
		for (int i = 0; i < n+1; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
	}
}
