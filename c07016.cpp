#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Contestant {
	int id;
	char name[100];
	char dob[12];
	float score[3];
};

typedef struct Contestant ctt;

ctt enter() {
	ctt c;
	gets(c.name);
	gets(c.dob);
	for (int i = 0; i < 3; i++) {
		scanf("%f", &c.score[i]);
	}
	getchar();
	return c;
}

int cmp(const void *a, const void *b) {
	ctt *pa = (ctt*)a;
	ctt *pb = (ctt*)b;
	
	float sum_a = pa->score[0] + pa->score[1] + pa->score[2];
	float sum_b = pb->score[0] + pb->score[1] + pb->score[2];
	
	if (sum_a < sum_b) {
		return 1;
	}
	
	if (sum_a > sum_b) {
		return -1;
	}
	
	return 0;
}

void show(ctt c) {
	printf("%d ", c.id);
	for (int i = 0; i < strlen(c.name); i++) {
		printf("%c", c.name[i]);
	}
	printf(" %s", c.dob);
	printf(" %.1f\n", c.score[0] + c.score[1] + c.score[2]);
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	
	float sum = 0;
	ctt a[n];
	for (int i = 0; i < n; i++) {
		a[i] = enter();
		a[i].id = i + 1;
		float s = a[i].score[0] + a[i].score[1] + a[i].score[2];
		sum = (sum < s)? s:sum;
	}
	
	qsort(a, n, sizeof(ctt), cmp);
	
	for (int i = 0; i < n; i++) {
		show(a[i]);
	}
}
