#include <stdio.h>
#include <string.h>
#include <ctype.h>

void check(char s[], int n) {
	
	for (int i = 0; i < n; i++) {
		if (!isdigit(s[i])) {
			printf("INVALID\n");
			return;
		}
	}
	
	int even = 0, odd = 0;
	for (int i = 0; i < n; i++) {
		if ((s[i] - '0') % 2 == 0) {
			even++;
		} else {
			odd++;
		}
	}
	
	if ((n % 2 == 0 && even > odd) || (n % 2 == 1 && even < odd)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	int t;
	scanf("%d", &t);
	
	getchar();
	while(t--) {
		char s[1001];
		gets(s);
		int n = strlen(s);
		
		check(s, n);
	}
}
