#include <stdio.h>

void RG(int *a, int *b) {
	int i = 2;
	while(i <= *a && i <= *b) {
		if (*a % i == 0 && *b % i == 0) {
			*a /= i;
			*b /= i;
		} else {
			i++;
		}
	}
}

int ucln(int a, int b) {
	if (b == 0) {
		return a;
	}
	return ucln(b, a % b);
}

int bcnn(int a, int b) {
	return a*b / ucln(a, b);
}

int main() {
	int t;
	scanf("%d", &t);
	
	for (int k = 1; k <= t; k++) {
		int a[4];
		for (int i = 0; i < 4; i++) {
			scanf("%d", &a[i]);
		}
		
		// rút gọn phân số
		RG(&a[0], &a[1]);
		RG(&a[2], &a[3]);
		
		// quy đồng
		int LCM = bcnn(a[1], a[3]);
		a[0] = a[0] * (LCM/a[1]);
		a[2] = a[2] * (LCM/a[3]);
		a[1] = a[3] = LCM;
		
		// tổng 2 phân số
		int p_b, q_b;
		p_b = a[0] + a[2];
		q_b = a[1];
		RG(&p_b, &q_b);
		
		// chia 2 phân số
		int p_c, q_c;
		p_c = a[0] * a[3];
		q_c = a[1] * a[2];
		RG(&p_c, &q_c);
		
		printf("Case #%d:\n", k);
		printf("%d/%d %d/%d\n", a[0], a[1], a[2], a[3]);
		printf("%d/%d\n", p_b, q_b);
		printf("%d/%d\n", p_c, q_c);
	}
}
