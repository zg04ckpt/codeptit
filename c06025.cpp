#include <stdio.h>
#include <string.h>

// so sánh 2 số s1, s2
int cmp(char s1[], char s2[]) {
	
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	if (n1 > n2) {
		return 1;
	} else if (n1 < n2) {
		return 0;
	}
	
	for (int i = 0; i < n1; i++) {
		if (s1[i] > s2[i]) {
			return 1;
		}
		
		if (s1[i] < s2[i]) {
			return 0;
		}
	}
}

int convert(char s1[], char s2[], int s[]) {
	
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	int n = (n1 > n2)? n1:n2;
	
	int S1[n]; 
	int S2[n];
	for (int i = 0; i < n; i++) {
		S1[i] = 0;
		S2[i] = 0;
		s[i] = 0;
	}
	
	n1--;
	n2--;
	for (int i = n - 1; n1 >= 0; i--) {
		S1[i] = s1[n1--] - '0';
	}
	for (int i = n - 1; n2 >= 0; i--) {
		S2[i] = s2[n2--] - '0';
	}
	
	int memo = 0, res;
	if (cmp(s1, s2)) {
		for (int i = n - 1; i >= 0; i--) {
			res = (S1[i] - memo) - S2[i];
			if (res < 0) {
				res += 10;
				memo = 1;
			} else {
				memo = 0;
			}
			s[i] = res;
		}
	} else {
		for (int i = n - 1; i >= 0; i--) {
			res = (S2[i] - memo) - S1[i];
			if (res < 0) {
				res = (S2[i] - memo) + 10 - S1[i];
				memo = 1;
			} else {
				memo = 0;
			}
			s[i] = res;
		}
	}
	
	return n;
}

int main() {
	int t;
	scanf("%d", &t);
	
	getchar();
	while(t--) {
		char s1[501], s2[501]; 
		int s[502];
		gets(s1);
		gets(s2);
		
		int n = convert(s1, s2, s);
		
		for (int i = 0; i < n; i++) {
			if (s[i] != 0) {
				while(i < n) {
					printf("%d", s[i++]);
				}
				break;
			}
		}
		printf("\n");
	}
}
