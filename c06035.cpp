#include <stdio.h>
#include <string.h>

int checkTN(char s[]) {
	int n = strlen(s);
	int count = 0;
	for (int i = 0; i < n/2; i++) {
		if (s[i] != s[n-1-i]) {
			count++;
		}
	}
	return count;
}

int main() {
	int t;
	scanf("%d", &t);
	
	getchar();
	while(t--) {
		char s[101];
		gets(s);
		int n = strlen(s);
		
		if (n % 2 == 0) {
			if (checkTN(s) == 1) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			if (checkTN(s) <= 1) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
}
