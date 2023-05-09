#include <stdio.h>
#include <string.h>

int main() {
	int t;
	scanf("%d", &t);
	
	getchar();
	while(t--) {
		char s1[200], s2[200];
		gets(s1);
		gets(s2);
		int n1 = strlen(s1);
		int n2 = strlen(s2);
		
		for (int i = 0; i < n1; i++) {
			if (s1[i] == ' ') {
				s1[i] = '\0';
			}
		}
		
		for (int i = 0; i < n2; i++) {
			if (s2[i] == ' ') {
				s2[i] = '\0';
			}
		}
		
		for (int i = 0; i < n1; i++) {
			if (i == 0 || (s1[i - 1] == '\0' && s1[i] != '\0')) {
				char temp1[200];
				strcpy(temp1, s1 + i);
				for (int j = 0; j < n2; j++) {
					if (j == 0 || (s2[j - 1] == '\0' && s2[j] != '\0')) {
						char temp2[200];
						strcpy(temp2, s2 + j);
						if (strcmp(temp1, temp2) == 0) {
							while(s1[i] != '\0') {
								s1[i++] = '\0';
							}
							break;
						}
					}
				}
			}
		}
		
		for (int i = 0; i < n1; i++) {
			if (i == 0 || (s1[i - 1] == '\0' && s1[i] != '\0')) {
				char temp1[200];
				strcpy(temp1, s1 + i);
				for (int j = i + 1; j < n1; j++) {
					if (s1[j] != '\0' && s1[j - 1] == '\0') {
						char temp2[200];
						strcpy(temp2, s1 + j);
						if (strcmp(temp1, temp2) == 0) {
							while(s1[j] != '\0') {
								s1[j++] = '\0';
							}
							j--;
						}
					}
				}
			}
		}
		
		char s3[101][101];
		int count3 = 0;
		for (int i = 0; i < n1; i++) {
			if (s1[i] != '\0') {
				int count4 = 0;
				while(s1[i] != '\0') {
					s3[count3][count4++] = s1[i++]; 
				}
				s3[count3][count4] = '\0';
				count3++;
			}
		}
		
		for (int i = 0; i < count3; i++) {
			for (int j = i + 1; j < count3; j++) {
				if (strcmp(s3[i], s3[j]) > 0) {
					char temp[101];
					strcpy(temp, s3[i]);
					strcpy(s3[i], s3[j]);
					strcpy(s3[j], temp);
				}
			}
		}
		
		for (int i = 0; i < count3; i++) {
			printf("%s", s3[i]);
			if (i != count3 - 1) {
				printf(" ");
			}
		}
		
		printf("\n");
	}
}
