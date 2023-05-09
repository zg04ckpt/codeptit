#include <stdio.h>
#include <string.h>
#include <ctype.h>

void link(char s[], char c) {
	int n = strlen(s);
	for (int i = n; i > 0; i--) {
		s[i] = s[i-1];
	}
	s[0] = c;
	s[n + 1] = '\0';
}

int checkTN(char s[]) {
	int n = strlen(s);
	for (int i = 0; i < n/2; i++) {
		if (s[i] != s[n-1-i]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	char s[10001][101];
	int max = 0;
	
//	int n = 0;
//	while(1) {
//		char c = getchar();
//		if (c == '\n') {
//			break;
//		} else {
//			char temp[1001];
//			scanf("%s", temp);
//			link(temp, c);
//			if (checkTN(temp)) {
//				strcpy(s[n++], temp);
//				max = (max < strlen(temp))? strlen(temp):max;
//			}
//		}
//		getchar();
//	}

	int n = 0;
	char temp[10005];
	while(gets(temp)) {
		char *token = strtok(temp, " ");
		while(token != NULL) {
			if (checkTN(token)) {
				int len = strlen(token);
				max = (max < len)? len:max;
				strcpy(s[n++], token);
			}
			
			token = strtok(NULL, " ");
		}
	}
	
//	for (int i = 0; i < n; i++) {
//		printf("%s\n", s[i]);
//	}
	
	int count[n];
	for (int i = 0; i < n; i++) {
		count[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (strlen(s[i]) == max && count[i] != 0) {
			for (int j = i + 1; j < n; j++) {
				if (strcmp(s[i], s[j]) == 0) {
					count[i]++;
					count[j] = 0;
				}
			}
		} else {
			count[i] = 0;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (count[i] != 0) {
			printf("%s %d\n", s + i, count[i]);
		}
	}
}
