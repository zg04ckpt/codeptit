#include <stdio.h>

// mảng để sàng số NT theo kiểu số thứ i là số NT nếu prime[i] = 1;
int prime[10000001];

//mảng chứa toàn số NT
int p[100000];

void seive() {
	prime[0] = prime[1] = 0;
	// đầu tiên cho toàn bộ mảng là 1
	for (int i = 2; i < 10000001; i++) {
		prime[i] = 1;
	}
	
	// biến đếm số pt của mảng p
	int n = 0;
	
	// sàng số nt
	for (int i = 2; i*i <= 10000001; i++) {
		if (prime[i]) {
			p[n++] = i;
			for (int j = i*i; j <= 10000001; j += i) {
				prime[j] = 0;
			}
		}
	}
	// gán pt cuối của p là -1 để đánh dấu kết thúc chuỗi
	p[n] = -1;
}

// kiểm tra theo cách thông thường cải biến
// chia cho các số nt từ bé đến lớn chia hết thì kp số NT
int check(long long n) {
	for (int i = 0; p[i] != -1; i++) {
		if (n % p[i] == 0) {
			return 0;
		}
	}
	return 1;
}

// kiểm tra các tp là số nt và tổng là số NT
int check2(long long n) {
	int sum = 0;
	while(n > 0) {
		int c = n % 10;
		sum += c;
		if (!prime[c]) {
			return 0;
		}
		n /= 10;
	}
	
	if (!prime[sum]) {
		return 0;
	}
	
	return 1;
}

int main() {
	// sàng để khởi tạo
	seive();
	int t;
	scanf("%d", &t);
	
	while(t--) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
	
		int count = 0;
		for (long long i = a; i <= b; i++) {
			// nếu số bé hơn 10tr thì dùng sàng NT để ktra cho nhanh
			if (i < 10000001) {
				if (prime[i] && check2(i)) {
					count++;
				}
			// nếu số lớn hơn 10tr thì dùng cách thông thường
			} else {
				if (check(i) && check2(i)) {
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	
}
