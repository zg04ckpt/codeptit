#include <stdio.h>
#include <math.h>

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int N, p, count = 0;
		scanf("%d%d", &N, &p);
		
		//tìm đếm xem từ 1 đến N có bn số chia hết cho p mũ 1,2,...
		for(int i = p; i <= N; i *= p) {
			count += N / i;
		}
		printf("%d\n", count);
	}
	return 0;
}
