#include <stdio.h>
#include <stdbool.h>
/* Cách khác
Bước 1: Tính các số nguyên tố từ 1 đến 100. Các số nguyên tố từ 1 đến 100 là: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89 và 97.

Bước 2: Với mỗi số từ 1 đến 100, ta phân tích số đó thành tích các thừa số nguyên tố. Ví dụ, số 12 có thể phân tích thành tích của các số nguyên tố sau: 12 = 2^2 × 3.

Bước 3: Tìm số lượng lớn nhất của mỗi thừa số nguyên tố trong các phân tích trên. Ví dụ, nếu ta xét các phân tích của số 12 và số 24, ta thấy rằng số 12 có 2 thừa số 2, trong khi số 24 chỉ có 1 thừa số 2. Do đó, số lượng lớn nhất của thừa số 2 trong các phân tích từ 1 đến 100 là 2.

Bước 4: Tính bội chung nhỏ nhất bằng cách nhân tất cả các thừa số nguyên tố với số lượng lớn nhất
*/

//Cách đang dùng : tìm BCNN của các số từ 1 đến n.
unsigned long long arr[101];

unsigned long long GCD(unsigned long long a, unsigned long long b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

unsigned long long LCD(unsigned long long a, unsigned long long b) {
	return (a * b)/GCD(a, b);
}

void khoitao() {
	unsigned long long temp = 1;
	arr[1] = 1;
	for (int i = 2; i <= 100; i++) {
		temp = LCD(temp, i);
		arr[i] = temp;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	khoitao();
	
	while(t--) {
		int n, kq = 1;
		scanf("%d", &n);
		printf("%lld\n", arr[n]);
	}
}
