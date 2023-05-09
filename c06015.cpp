#include <stdio.h>
#include <ctype.h>
#include <string.h>

void format1(char s[]) {
	int n = strlen(s);
	s[0] = toupper(s[0]);
	for (int i = 1; i < n; i++) {
		s[i] = tolower(s[i]);
	}
}

void format2(char s[]) {
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		s[i] = toupper(s[i]);
	}
}

int main() {
	int t;
	scanf("%d", &t);
	
	getchar();
	while(t--) {
		char s[1000];
		gets(s);
		
		char firstName[25];
		
		// tách bởi dấu cách, lấy từ đầu tiên
		char *tok = strtok(s, " ");
		strcpy(firstName, tok);
		format2(firstName); // In hoa họ
		
		tok = strtok(NULL, " ");
		while(tok != NULL) {
			format1(tok); // In thường viết hoa đầu
			printf("%s", tok);
			tok = strtok(NULL, " ");
			if (tok == NULL) {
				printf(", ");
			} else {
				printf(" ");
			}
		}
		
		printf("%s\n", firstName);
	}
	
}
