#include<stdio.h> 

int main(){ 
	int t; 
	long long SUM = 0;
	scanf("%d",&t); 
	
	while(t--){ 
		long long n; 
		scanf("%lld",&n); 
		
		long long sum = 0; 
		for(int i=2;i<=n;i++){ 
			while(n%i==0){ 
				sum += i; 
				n=n/i; 
			} 
		} 
		SUM += sum;
	} 
	printf("%lld\n", SUM);
}
