#include <stdio.h>
#include <string.h>

// hàm kiểm tra số không giảm
int check(char s[]) {
	int n = strlen(s);
	for (int i = 0; i < n - 1; i++) {
		if (s[i] > s[i+1]) {
			return 0;
		}
	}
	return 1;
}

// hàm tráo đổi số
void swapN(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// hàm tráo đổi từ
void swapC(char a[], char b[]) {
	char temp[10];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}

int main() {
	char s[1000001];
	char res[100000][10];
	
	// tạo chuỗi n số không giảm
	int n = 0;
	while(gets(s)) {
		char* token = strtok(s, " ");
		while(token != NULL) {
			if (check(token)) {
				strcpy(res[n++], token);
			}
			token = strtok(NULL, " ");
		}	
	}
	
	// gán toàn bộ mảng đánh đấu là 1
	int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = 1;
	}

	// điếm số lần xuất hiện của số tương ứng với a[i]
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			for (int j = i + 1; j < n; j++) {
				if (strcmp(res[i], res[j]) == 0) {
					a[i]++;
					a[j] = 0;
				}
			}
		}
	}

	// hàm sắp xếp theo số lần xuất hiện tăng dần
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			for (int j = i + 1; j < n; j++) {
				if (a[j] && a[i] < a[j]) {
					swapN(&a[i], &a[j]);
					swapC(res[i], res[j]);
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i]) {
			printf("%s %d\n", res[i], a[i]);
		}
	}
}
