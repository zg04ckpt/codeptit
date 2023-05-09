#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// ghép 2 chuỗi ab và ba rồi so sánh xem cái nào nhỏ hơn
int check(char a[], char b[]) {
	
	char s1[200];
	char s2[200];
	strcpy(s1, a);
	strcpy(s2, b);

	strcat(s1, b);
	strcat(s2, a);
	
	if (strcmp(s1, s2) <= 0) {
		return 0;
	}
	return 1;
}

void swap(char a[], char b[]) {
	char c[200];
	strcpy(c, a);
	strcpy(a, b);
	strcpy(b, c);
}

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int n;
		scanf("%d", &n);
		
		char s[n][200];
		for (int i = 0; i < n; i++) {
			scanf("%s", s[i]);
			s[i][strlen(s[i])] = '\0';
		}
		
		// sắp xếp nổi bọt 
		int m = 1;
		while(m) {
			m = 0;
			for (int i = 0; i < n-1; i++) {
				if (check(s[i], s[i+1])) {
					swap(s[i], s[i+1]);
					m = 1;
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			printf("%s", s[i]);
		}
		
		printf("\n");
	}
}