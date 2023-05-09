#include <stdio.h>

int convert(int n, int m) {
	if (n % m != 0) {
		return n/m + 1;
	}
	return n / m;
}

int main() {
	
	//chiều dài đường, SL đèn đang HĐ, Tầm chiếu sáng
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);
	//các vị trí của ngọn đèn, mảng đánh dấu vị trí được chiếu sáng
	int a[M + 1], S[N + 1];
	for(int i = 1; i <= N; i++) {
		S[i] = 0;
	}
	
//	for(int i = 1; i <= N; i++) {
//		printf("%d ", S[i]);
//	}
//	printf("\n");	
	
	//chiếu sáng
	for(int i = 1; i <= M; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i = 1; i <= M; i++) {
		if (a[i] - K >= 1 && a[i] + K <= N) {
			for (int j = a[i] - K; j <= a[i] + K; j++) {
				S[j] = 1;
			}
		} else if (a[i] - K < 1) {
			for (int j = 1; j <= a[i] + K; j++) {
				S[j] = 1;
			}
		} else if (a[i] + K > M) {
			for (int j = N; j >= a[i] - K; j--) {
				S[j] = 1;
			}
		}
	}
	
//	for(int i = 1; i <= N; i++) {
//		printf("%d ", S[i]);
//	}
//	printf("\n");
	
	//số đèn cần chiếu sáng, chiều dài chưa chiếu sáng
	int D = 0, len = 0;
	for(int i = 1; i <= N; i++) {
		while(S[i] == 0) {
			len++;
			i++;
			continue;
		}
		int check = convert(len, 2 * K + 1);
		if (check != 0) {
			D += check;
			len = 0;
		}
	}
	
	printf("%d", D);
}
