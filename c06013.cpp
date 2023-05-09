#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isDigit(char s[], int n) {
	for (int i = 0; i < n; i++) {
		if (!isdigit(s[i])) {
			return 0;
		}
	}
	return 1;
}

int check(char s[], int n) {
	
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != ' ') {
			for (int j = i + 1; j < n; j++) {
				if (s[j] == s[i]) {
					s[j] = ' ';
				}
			}
		}
	}
	
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != ' ') {
			count++;
		}
	}
	
	return count == 10;
}

int lastestCheck(char s[], int n) {
	
	if (s[0] == '0' || !isDigit(s, n)) {
		return 1;
	}
	
	if (check(s, n)) {
		return 2;
	}
	
	return 3;
}

int main() {
	int t;
	scanf("%d", &t);
	
	getchar();
	while(t--) {
		char s[10000];
//		scanf("%s", s);
		gets(s);
	
		int control = lastestCheck(s, strlen(s));
		if (control == 1) {
			printf("INVALID\n");
		} else if (control == 2) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
