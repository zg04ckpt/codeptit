#include <stdio.h>
#include <string.h>

// tính tổng các chữ số
int sum(char s[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += s[i] - '0';
	}
	return sum;
}

// nhân theo mảng với 1 số nguyên
void nhan(char s[], int n, int m) {
	
	// chuyển mảng s thành số tương ứng, đồng thời copy ra s1
	char s1[61];
	for (int i = 0; i < n; i++) {
		s[i] -= '0';
		s1[i] = s[i];
	}
	
	// nhân với số 1 chữ số
	int memo = 0;
	for (int i = n-1; i >= 0; i--) {
		s[i] *= m%10;
		s[i] += memo;
		memo = s[i] / 10;
		s[i] %= 10;
	}

	/* nếu m > 10 thì nhân 2 chữ số
    lấy s1 nhân với số hàng chục rồi đem cộng với s
	 123
	x
	  23
	----
	 369
	246
	----
	2829
	*/
	if (m >= 10) {
		m /= 10;
		int memo = 0;
		for (int i = n-1; i >= 0; i--) {
			s1[i] *= m;
			s1[i] += memo;
			memo = s1[i] / 10;
			s1[i] %= 10;
		}
		
		int memo2 = 0;
		for (int i = n-2; i >= 0; i--) {
			s[i] += s1[i+1];
			s[i] += memo;
			memo = s[i] / 10;
			s[i] %= 10;
		}
	}
	
	for (int i = 0; i < n; i++) {
		s[i] += '0';
	}
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	
	while(t--) {
		char s[61];
		gets(s);
		int n = strlen(s);
		
		// mảng 2 chiều chứa các kq chuỗi s nhân với các số từ 1 đến n
		char S[n][61];
		for (int i = 0; i < n; i++) {
			// copy s ra m rồi dung m để nhân
            char m[61];
            strcpy(m, s);
            nhan(m, n, i+1);
            
			strcpy(S[i], m);
		}
		
		/*
		thuật toán: cộng tất cả giá trị các số ở hàng tương ứng của các S[i], 
		nếu mảng a ra kết quả tất cả phần tử đều bằng nhau và bằng tổng
		các chữ số của s thì s là số vòng.
		*/
		int a[n];
		for (int i = 0; i < n; i++) {
			a[i] = 0;
			for (int j = 0; j < n; j++) {
				a[i] += S[i][j] - '0';
			}
		}
		
		int check = 1;
		if (a[0] != sum(s, n)) {
			check = 0;
		} else {
			for (int i = 1; i < n; i++) {
				if (a[i] != a[i-1]) {
					check = 0;
					break;
				}
			}
		}
		
		if (check == 1) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
