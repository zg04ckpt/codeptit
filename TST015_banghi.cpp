#include <stdio.h>
#include <math.h>

typedef struct Triangle { 
	int a;
	int b;
	int c;
	
} Triangle;

void show(Triangle tri) {
		printf("%d %d %d\n", tri.a, tri.b, tri.c);
}
	
double calcArea(Triangle tri) {
	int a = tri.a;
	int b = tri.b;
	int c = tri.c;
	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void enter(Triangle *tri) {
	scanf("%d %d %d", &tri->a, &tri->b, &tri->c);
}

void writeToBinFile(Triangle *triangle) {
	FILE *file;
	file = fopen("FPLSP22GxxmsvTG.fpl", "wb");
	if (file != NULL) {
		fwrite(triangle, sizeof(triangle), 1, file);
	} else {
		printf("FAIL!\n");
		return;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	Triangle array[t];
	
	for (int i = 0; i < t; i++) {
		Triangle triangle;
		enter(&triangle);
		array[i] = triangle;
	}
	
	for (int i = 0; i < t; i++) {
		for (int j = i + 1; j < t; j++) {
			if (calcArea(array[i]) > calcArea(array[j])) {
				Triangle triangle = array[i];
				array[i] = array[j];
				array[j] = triangle;
			}
		}
	}
	
	for (int i = 0; i < t; i++) {
		show(array[i]);
	}
	
	return 0;
}
