#include <stdio.h>

long long A[2][2], B[2][2];

void calc(long long A[2][2], long long B[2][2]) {
	long long x = B[0][0] * A[0][0] + B[0][1] * A[1][0];
	long long y = B[0][0] * A[0][1] + B[0][1] * A[1][1];
	long long z = B[1][0] * A[0][0] + B[1][1] * A[1][0];
	long long t = B[1][0] * A[0][1] + B[1][1] * A[1][1];
	B[0][0] = x;
	B[0][1] = y;
	B[1][0] = z;
	B[1][1] = t;
}

long long calc2(int n) {
	if(n == 1) {
		return 0;
	}
	A[0][0] = B[0][0] = 0;
	A[0][1] = B[0][1] = 1;
	A[1][0] = B[1][0] = 1;
	A[1][1] = B[1][1] = 1;
	for (int i = 1; i < n - 1; i++) {
		calc(A, B);
	}
	return B[0][1];
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        long long n;
        scanf("%lld", &n);
        
        int i = 1, isNo = 1;
        while (1) {
        	
        	long long check = calc2(i);
        	
        	if (check > n) {
        		break;
			}
        	
        	if(check == n) {
        		printf("YES\n");
        		isNo = 0;
        		break;
			} else {
				i++;
			}
		}
		
		if(isNo == 1) {
			printf("NO\n");
		}
    }
    return 0;
}