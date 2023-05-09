#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
	int t;
	scanf("%d", &t);
	
	getchar();
	while(t--) {
		char s[10000], s1[10000];
		gets(s);
		int n = strlen(s);
		
		for (int i = 0; i < n; i++) {
			if (i == 0 || (s[i - 1] == ' ' && isalpha(s[i]))) {
				s[i] = toupper(s[i]);
			} else {
				s[i] = tolower(s[i]);
			}
		}
		
		for (int i = 0; i < n; i++) {
			if (s[i] == ' ') {
				s[i] = '\0';
			}
		}
		
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != '\0') {
				s1[count++] = s[i];
			}
		}
		
		printf("%c", s1[0]);
		for (int i = 1; i < count; i++) {
			if (s1[i] >= 'A' && s1[i] <= 'Z') {
				printf(" ");
			}
			printf("%c", s1[i]);
		}
		printf("\n");
	}
}
