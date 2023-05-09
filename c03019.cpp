#include <stdio.h>
#include <math.h>

int checkTN(long long n) {
	long long m = n, k = 0;
	while (m > 0) {
		k += m % 10;
		m /= 10;
		if (m > 0) {
			k *= 10;
		}
	}
	if (k == n) {
		return 1;
	}
	return 0;
}

int checkSum(long long n) {
	int sum = 0;
	while(n > 0) {
		sum += n % 10;
		n /= 10;
	}
	if (sum % 10 == 0) {
		return 1;
	}
	return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
    	int n, count = 0;
    	scanf("%d", &n);
    	int a[n];
    	
    	long long max = (long long) pow(10, n);
    	long long min = (long long) pow(10, n - 1);
    	for (long long i = min; i < max; i++) {
    		if (checkTN(i) && checkSum(i)) {
    			count++;
			}
		}
    	
    	printf("%d\n", count);
	}

    return 0;
}