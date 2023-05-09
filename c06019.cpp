#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char s[100], email[100];
	gets(s);
	int n = strlen(s), flag;
	
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] != ' ' && s[i - 1] == ' ') {
			flag = i - 1;
			break;
		}
	}
	
	int m = 0;
	for (int i = 0; i < flag; i++) {
		if (i == 0 || (s[i - 1] == ' ' && s[i] != ' ')) {
			email[m++] = s[i];
		}
	}
	
	for (int i = flag + 1; i < n; i++) {
		if (s[i] != ' ') {
			while(i < n && s[i] != ' ') {
				email[m++] = s[i++];
			}
			break;
		}
	}
	
	for (int i = 0; i < m; i++) {
		email[i] = tolower(email[i]);
		printf("%c", email[i]);
	}
	
	char a[] = "@ptit.edu.vn";
	printf("%s", a);
}
