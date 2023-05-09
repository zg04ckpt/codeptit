#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    const char* sa = *(const char**)a;
    const char* sb = *(const char**)b;
    return strcmp(sa, sb);
}

int main() {
	
	char s1[101][101], s2[101][101];
	
	int n1 = 0;
	while(1) {
		scanf("%s", s1[n1++]);
		if (getchar() == '\n') {
			break;
		}
	}
	
	int n2 = 0;
	while(1) {
		scanf("%s", s2[n2++]);
		if (getchar() == '\n') {
			break;
		}
	}
	
//	for (int i = 0; i < n1; i++) {
//		for (int j = i + 1; j < n1; j++) {
//			if (strcmp(s1[i], s1[j]) > 0) {
//				char temp[101];
//				strcpy(temp, s1[i]);
//				strcpy(s1[i], s1[j]);
//				strcpy(s1[j], temp);
//			}
//		}
//	}
	
	qsort(s1, n1, sizeof(s1[0]), compare);
	
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (strcmp(s1[i], s2[j]) == 0) {
				s1[i][0] = '\0';
				break;
			}
		}
	}
	
	for (int i = 0; i < n1; i++) {
		if (s1[i][0] != '\0') {
			printf("%s ", s1[i]);
		}
	}
}
