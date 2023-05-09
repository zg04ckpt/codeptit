#include <stdio.h>
#include<stdbool.h>
#include<string.h>

bool kt_doi_xung(char s[], int n) {
	for (int i = 0; i <= n / 2; i++) {
		if (s[i] != s[n - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	
	char s[100001];
	
	gets(s);
	int len = strlen(s);
	int count = len - 1;
	printf("%d", count);
	
//	while(true) {
//		if (kt_doi_xung(s , len - count)) {
//			printf("%d", count);
//			break;
//		} else {
//			count++;
//		}
//	}
	
	return 0;
}
