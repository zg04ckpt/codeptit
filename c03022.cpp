#include <stdio.h>
#include <stdbool.h>

bool prime[100000];

void seive() {
	for (int i = 1; i <= 100000; i++) {
		prime[i] = true;
	}
	
	for (int i = 2; i * i <= 100000; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= 100000; j += i) {
				prime[j] = false;
			}
		}
	}
}

bool checkSum(int n) {
	int sum = 0;
	while(n > 0) {
		sum += n % 10;
		n /= 10;
	}
	if (sum % 5 == 0) {
		return true;
	}
	return false;
}

int main() {
	int n, count = 0;
	scanf("%d", &n);
	
	seive();
	for (int i = 5; i < n; i++) {
		if (prime[i] && checkSum(i)) {
			printf("%d ", i);
			count++;
		}
	}
	printf("\n%d", count);
	return 0;
}
