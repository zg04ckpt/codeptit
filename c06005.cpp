#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char c[100000];
	gets(c);
	int n = strlen(c);
	int a[n], count = 0;
	memset(a, 0, sizeof(a));
	
	// thành chữ in thường
	for (int i = 0; i < n; i++) {
		c[i] = tolower(c[i]);
	}
	
	// tạo mảng song song đếm độ dài chuỗi, khoảng trắng tương đương 0
	// cao cao hang
	//0123012301234
	for (int i = 0; i < n; i++) {
		if (count == 0 && c[i] != ' ') {
			count = 1;
		} else if (c[i] != ' ') {
			count++;
		} else {
			count = 0;
		}
		a[i] = count;
	}
	
	// mảng char chứa các từ cần so
	char check[n]; 
	memset(check, ' ', sizeof(check));
	// biến đếm lần xuất hiện
	int count2 = 1;
	for (int i = 0; i < n; i++) {
		// nếu kí tự hiện tại không phải khoảng trắng 
		// && kí tự sau nó là khoảng khắng hoặc là kí tự cuối 
		if (a[i] != 0 && (i == n - 1 || a[i + 1] == 0)) {
			
			// tạo mảng chứa từ cần đếm
			int m = i;
			while(m >= 0 && a[m] != 0) {
				check[a[m]] = c[m];
				m--;
			}
			
			// duyệt từ cuối lại nếu thấy từ nào có độ dài giống thì kiểm tra
			for (int j = n - 1; j > i; j--) {
				if (a[j] == a[i]) {
					
					int isSame = 1;
					for (int k = j; a[k] >= 1; k--) {
						if (c[k] != check[a[k]]) {
							isSame = 0;
							break;
						}
					}
					
					// nếu giống thì biến đếm +1 và toàn bộ kí tự vừa kiểm tra thành khoảng trắng để không kt lần 2
					if (isSame) {
						count2 += 1;
						for (int k = j; a[k] >= 1; k--) {
							a[k] = 0;
							c[k] = ' ';
						}
					}
					
				}
			}
			
			for (int j = 1; j <= a[i]; j++) {
				printf("%c", check[j]);
			}
			printf(" %d\n", count2);
			memset(check, ' ', sizeof(check));
			count2 = 1;
		}
	}
}
