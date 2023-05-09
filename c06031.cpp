#include <stdio.h>
#include <string.h>

int fmax(int a, int b) {
	return (a>b)? a:b;
}

int main() {
	char s[200];
	gets(s);
	int n = strlen(s), res = 0;

	int mark[n];
	mark[0] = 1;
	//abcde fghijklmnopqrstuvwxyz
	// đánh dấu như sau : aiemckgobjfndlhp
	//                    1223233424353546
	//tăng theo thứ tự không liên tiếp
	for (int i = 0; i < n; i++) {
		int max = 1;
		for (int j = 0; j < i; j++) {
			if (s[i] > s[j] && mark[j] + 1 > max) max = mark[j] + 1;
		}

		mark[i] = max;
		res = fmax(res, max);
	}
	
//	for (int i = 0; i < n; i++) {
//		printf("%d", mark[i]);
//	}

	printf("\n%d", 26 - res);

	printf("\n");

	return 0;
}
                    