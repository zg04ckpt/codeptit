#include <stdio.h>
#include <math.h>

int checkTN6(int n) {
	int have6 = 0;
	int m = n, k = 0;
	while (m > 0) {
		if (m % 10 == 6) {
			have6 = 1;
		}
		k += m % 10;
		m /= 10;
		if (m > 0) {
			k *= 10;
		}
	}
	if (k == n && have6 == 1) {
		return 1;
	}
	return 0;
}

int checkSum8(int n) {
	int sum = 0;
	while(n > 0) {
		sum += n % 10;
		n /= 10;
	}
	if (sum % 10 == 8) {
		return 1;
	}
	return 0;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    
    if (a > b) {
    	int c = a;
    	a = b;
    	b = c;
	}
    
    for (int i = a; i <= b; i++) {
    	if (checkTN6(i) && checkSum8(i)) {
    		printf("%d ", i);
		}
	}
}