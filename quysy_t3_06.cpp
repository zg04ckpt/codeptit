#include <stdio.h>
#include <string.h>

long UocSo;

long long gcd(long a, long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

void USCLN(long a, long b) {
	UocSo = gcd(a, b);
}

int main()
{
	long a, b;
	
	scanf("%ld%ld",&a, &b);
	if(a> 0 && b>0)
	{
		USCLN(a,b);
		printf("%ld\n%lld", UocSo, (long long) a*b/UocSo);
	}
}
