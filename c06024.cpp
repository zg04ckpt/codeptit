#include <stdio.h>
#include <string.h>

int convert(char s1[], char s2[], int s[]) {
	
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	int n = (n2 > n1)? n2:n1;
	n++;
	
	int S1[n]; 
	int S2[n];
	for (int i = 0; i < n; i++) {
		S1[i] = 0;
		S2[i] = 0;
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
	for (int i = n - 1; i >= 0; i--) {
		res = S1[i] + S2[i];
		s[i] = (res + memo) % 10;
		memo = (res + memo) / 10;
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
		
		if (s[0] != 0) {
			printf("%d", s[0]);
		}
		for (int i = 1; i < n; i++) {
			printf("%d", s[i]);
		}
		printf("\n");
	}
}
