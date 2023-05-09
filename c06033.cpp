#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void ghepxau(char s1[], char s2[], char s[], int N) {
	
	int c = 0;
	for (int i = 0; i < N; i++) {
		s[c++] = s2[i];
		s[c++] = s1[i];
	}
	
	s[c] = '\0';
}

void tachxau(char s[], char s1[], char s2[], int n) {
	
	for (int i = 0; i < n; i++) {
		s1[i] = s[i];
		s2[i] = s[i+n];
	}
}

int main() {
	int N;
	while(scanf("%d", &N) == 1) {
		getchar();
		if (N == 0) {
			break;
		}
		
		char s1[200], s2[200], s[400];
		gets(s1);
		gets(s2);
		gets(s);
		char first[400];// chuỗi kiểm tra xem có bị lặp lại hay không
		ghepxau(s1, s2, first, N);
		
		
		char cmp[400];
		int count = 0;
		while(1) {
			ghepxau(s1, s2, cmp, N);
//			printf("%s %s %s\n", s1, s2, cmp);
			count++;
			if (count > 1 && strcmp(cmp, first) == 0) {//lặp lại thì sai
				count = -1;
				break;
			}
			
			if (strcmp(cmp, s) == 0) {
				break;
			}
			
			tachxau(cmp, s1, s2, N);
		}
		
		printf("%d\n", count);
	}
}
