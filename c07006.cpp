#include <stdio.h>
#include <math.h>

double calc(double xA, double xB, double yA, double yB) {
	return sqrt((xA-xB)*(xA-xB) + (yA-yB)*(yA-yB));
}

double calcS(double a, double b, double c) {
	double p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		double xA, xB, xC, yA, yB, yC;
		scanf("%lf%lf%lf%lf%lf%lf", &xA, &yA, &xB, &yB, &xC, &yC);
		
		double a, b, c;
		a = calc(xB, xC, yB, yC);
		b = calc(xA, xC, yA, yC);
		c = calc(xA, xB, yA, yB);
		
		if (a + b <= c || a + c <= b || b + c <= a) {
			printf("INVALID\n");
		} else {
			printf("%0.2lf\n", calcS(a, b, c));
		}
	}
}
