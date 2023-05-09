#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Item {
	int seri;
	char name[1000];
	char type[1000];
	float input_price;
	float sell_price;
};

typedef struct Item it;

int comparator(const void *a, const void *b) {
	it *p_a = (it*)a;
	it *p_b = (it*)b;
	int x = p_a->sell_price - p_a->input_price;
	int y = p_b->sell_price - p_b->input_price;
	
	if (x > y) {
		return -1;
	} 
	
	if (x < y) {
		return 1;
	}
	
	return 0;
}

void import_product(it *a) {
	gets(a->name);
	gets(a->type);
	scanf("%f", &a->input_price);
	scanf("%f", &a->sell_price);
	getchar();
}

void show_product(it a) {
	printf("%d ", a.seri);
	for (int i = 0; i < strlen(a.name); i++) {
		printf("%c", a.name[i]);
	}
	printf(" ");
	for (int i = 0; i < strlen(a.type); i++) {
		printf("%c", a.type[i]);
	}
	printf(" %.2f\n", a.sell_price - a.input_price);
}


int main() {
	int n;
	scanf("%d", &n);
	getchar();
	it a[n];
	for (int i = 0; i < n; i++) {
		a[i].seri = i + 1;
		import_product(&a[i]);
	}
	
	qsort(a, n, sizeof(it), comparator);
	
	for (int i = 0; i < n; i++) {
		show_product(a[i]);
	}
}
