#include<stdio.h> 

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--) {
		long i = 2, n;
		scanf("%ld", &n);
		
		while (i * i <= n) {
			if (n % i == 0) {
				n /= i;
			} else {
				i++;
			}
		}
		
		printf("%ld\n", n);
	}
}