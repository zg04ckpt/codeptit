#include <stdio.h>

int a[200];

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int count = 0;
		while(1) {
			scanf("%d", &a[count++]);
			if(getchar() == '\n') break;
		}
		
		int c_even = 0;
		for (int i = 0; i < count; i++) {
			if (a[i] % 2 == 0) {
				c_even++;
			}
		}
		int c_odd = count - c_even;
		
		if (count % 2 == 0 && c_even > c_odd) {
			printf("YES\n");
		} else if (count % 2 != 0 && c_even < c_odd) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
