#include <stdio.h>

long calcNext(long n) {
	long sum = n--;
	while(n > 1) {
		sum += n--;
	}
	return sum;
}

//void cmp(long *x, long *y) {
//	if (*x > *y) {
//		int temp = *x;
//		*x = *y;
//		*y = temp;
//	}
//}

int main() {
	long a, b;
	while(scanf("%ld%ld", &a, &b) == 2) {
		getchar();
		long len = b - a;
		if (b < 0) {
			b *= -1;
		}
	
		/*
		m = độ dài bước
		rest = quãng đường tối tiểu đi được khi giảm bước từ m đến 1; VD m=3 -> rest = 3+2+1
		count = số bước đi
		*/
		long m = 1, rest = 0,count = 0;
		while(1) {
			long rest = calcNext(m);
			if (rest < len) {
				count++;
				len -= m;
			} else if (rest > len) {
				while(rest > len) {
					m--;
					rest = calcNext(m);
				}
				continue;
			} else {
				count += m;
				break;
			}
			m++;
		}
		
		printf("%d\n", count);
	}
	
}

/*
while(step > len) {
	m--;
	step = calcNext(m);
}
continue;
*/
