#include <stdio.h>

struct Pokemon {
	char name[100];
	int need;
	int have;
	int solanTH;
};

typedef struct Pokemon pkm;

int TH(pkm *p) {
	int a = p->need;
	int b = p->have;
	int count = 0;
	
	while (b >= a) {
		b -= a;
		b += 2;
		count++;
	}
	
	return count;
}

int main() {
	int n, max = 0, sum = 0;
	scanf("%d", &n);
	getchar();
	
	pkm a[n];
	for (int i = 0; i < n; i++) {
		gets(a[i].name);
		scanf("%d%d", &a[i].need, &a[i].have);
		getchar();
		
		int num = TH(&a[i]);
		if (num > max) {
			max = num;
		}
		sum += num;
	}
	
	for (int i = 0; i < n; i++) {
		int num = TH(&a[i]);
//		printf("%d\n", num);
		if (num == max) {
			printf("%d\n%s", sum, a[i].name);
			break;
		}
	}
}
