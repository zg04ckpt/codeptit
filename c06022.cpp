#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	int t;
	scanf("%d", &t);
	
	getchar();
	for (int k = 1; k <= t; k++) {
		
		char s1[201], s2[21];
		gets(s1);
		gets(s2);
		int n = strlen(s1);
		
		// xâu 2 thành chữ in thường
		for (int i = 0; i < strlen(s2); i++) {
			s2[i] = tolower(s2[i]);
		}
		
		// khoảng trắng s1 thành null
		for (int i = 0; i < n; i++) {
			if (s1[i] == ' ') {
				s1[i] = '\0';
			}
		}
		
		for (int i = 0; i < n; i++) {
			
			// nếu là từ đầu tiên hoặc là chữ cái mà trước là null
			if (i == 0 || (s1[i - 1] == '\0' && s1[i] != '\0')) {
				
				// copy sang chuỗi mới để so sánh
				char temp[201];
				strcpy(temp, s1 + i);
				
				// thành chữ thường
				for (int j = 0; j < strlen(temp); j++) {
					temp[j] = tolower(temp[j]);
				}
				
				// so sánh, nếu bằng nhau gán all bằng null
				if (strcmp(temp, s2) == 0) {
					while(s1[i] != '\0') {
						s1[i++] = '\0';
					}
				}
			}
		}
		
		printf("Test %d: ", k);
		for (int i = 0; i < n; i++) {
			
			// nếu là chữ đầu tiên
			if (i == 0 && s1[i] != '\0') {
				printf(" ");
			}
			
			// nếu vt hiện tại là null kế tiếp là chữ
			if (i != n - 1 && s1[i] == '\0' && s1[i + 1] != '\0') {
				printf(" ");
			}
			
			if (s1[i] != '\0') {
				printf("%c", s1[i]);
			}
		}
		printf("\n");
	}
}
