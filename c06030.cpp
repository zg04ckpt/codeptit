#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DemTu{
	char words[25];
	int c;// s? l?n xh
} DT;

int main() {
	DT S[1001];
	char s[10000];
	
	int n = 0, len_max = 0;
	while(gets(s)) {
		char *token = strtok(s, " ");
		while(token != NULL) {
			int len = strlen(token);
			if (len > len_max) {
				len_max = len;
			}
			
			strcpy(S[n++].words, token);
			token = strtok(NULL, " ");
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (strlen(S[i].words) == len_max) {
			S[i].c = 1;
		} else {
			S[i].c = -1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (S[i].c != -1) {
			for (int j = i+1; j < n; j++) {
				if (S[j].c != -1 && strcmp(S[i].words, S[j].words)==0) {
					S[i].c++;
					S[j].c = -1;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (S[i].c != -1) {
			printf("%s %d %d\n", S[i].words, len_max, S[i].c);
		}
	}
}