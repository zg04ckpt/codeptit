#include <stdio.h>
#include <string.h>

#define MAX 1000

int nextId = 1;

typedef struct Student {
	int id;
	char name[50];
	float scoreA;
	float scoreB;
	float scoreC;
} STD;

STD list[MAX];

void printString(char s[]) {
	for (int i = 0; i < strlen(s); i++) {
		printf("%c", s[i]);
	}
}

STD enter() {
	STD stu;
	stu.id = nextId++;
	gets(stu.name);
	scanf("%f%f%f", &stu.scoreA, &stu.scoreB, &stu.scoreC);
	getchar();
	return stu;
}

STD* update(STD *stu) {
	gets(stu->name);
	scanf("%f%f%f", &stu->scoreA, &stu->scoreB, &stu->scoreC);
	scanf("\n");
	return stu;
}

void printSTD(STD stu) {
	printf("%d ", stu.id);
	printString(stu.name);
	printf(" %0.1f %0.1f %0.1f\n", stu.scoreA, stu.scoreB, stu.scoreC);
}

int check(STD stu) {
	return stu.scoreA < stu.scoreB && stu.scoreB < stu.scoreC;
}

int main() {
	
	int t = 0;
	while(1) {
		scanf("%d", &t);
		if (t == 3) {
			break;
		}
		scanf("\n");

		switch(t) {
			case 1: {
				// số sinh viên thêm
				int n;
				scanf("%d", &n);
				int m = n;
				scanf("\n");
				for (int i = nextId-1; n > 0; i++) {
					list[i] = enter();
					n--;
				}
				
				printf("%d\n", m);
				break;
			}
			
			case 2: {
				// mã sinh viên để sửa
				int n;
				scanf("%d", &n);
				scanf("\n");
				
				update(&list[n-1]);
				printf("%d\n", n);
				break;
			}
			
			default:
				break;
		}
	}
	for (int i = nextId-2; i >= 0; i--) {
		printSTD(list[i]);
	}
}
