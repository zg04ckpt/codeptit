#include <stdio.h>
#include<stdbool.h>
#include<string.h>

bool kt_thuan_nghich(int num[], int n) {
	for (int i = 0; i <= n / 2; i++) {
		if (num[i] != num[n - 1 - i]) {
			return false;
		}
	}
	return true;
}

bool kt_chan(int num[], int n) {
	for (int i = 0; i < n; i++) {
		if (num[i] % 2 == 1) {
			return false;
		}
	}
	return true;
}

void chuyen_doi(char s[], int n, int num[]) {
	for (int i = 0; i < n; i++) {
		num[i] = s[i] - '0';
	}
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	
	while(t--) {
		char s[501];
		gets(s);
		
		int n = strlen(s);
		int num[n];
		chuyen_doi(s, n, num);
		
		if (kt_thuan_nghich(num, n) && kt_chan(num, n)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	
	return 0;
}
