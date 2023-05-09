#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
//	int i = 2;
//	while(n > 1) {
//		if (isPrime(i) && n%i == 0) {
//			if (n / i == 1) {
//				printf("%d", i);
//			} else {
//				printf("%dx", i);
//			}
//			n /= i;
//			continue;
//		}
//		i++;
//	}

	int i = 2;
	while(n > 1) {
		if (n % i == 0) {
			printf("%d", i);
			n /= i;
			if (n != 1) {
				printf("x");
			}
		} else {
			i++;
		}
	}
}
