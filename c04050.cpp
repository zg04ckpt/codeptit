#include <stdio.h>

void sortASC(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	int a[n], A[n], countA = 0; 
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	A[countA++] = a[0];
	for (int i = 1; i < n; i++) {
		int exsited = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (a[i] == a[j]) {
				exsited = 1;
				break;
			}
		}
		if (!exsited) {
			A[countA++] = a[i];
		}
	}
	
	int b[m], B[m], countB = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	
	B[countB++] = b[0];
	for (int i = 1; i < m; i++) {
		int exsited = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (b[i] == b[j]) {
				exsited = 1;
				break;
			}
		}
		if (!exsited) {
			B[countB++] = b[i];
		}
	}
	
	int AB[countA], cAB = 0;
	for(int i = 0; i < countA; i++) {
		for(int j = 0; j < countB; j++) {
			if (A[i] == B[j]) {
				AB[cAB++] = A[i];
				break;
			}
		}
	}
	
	int AnotB[countA], cAnB = 0;
	for(int i = 0; i < countA; i++) {
		AnotB[cAnB] = A[i];
		for(int j = 0; j < countB; j++) {
			if (A[i] == B[j]) {
				AnotB[cAnB] = NULL;
				break;
			}
		}
		cAnB++;
	}
	
	int BnotA[countB], cBnA = 0;
	for(int i = 0; i < countB; i++) {
		BnotA[cBnA] = B[i];
		for(int j = 0; j < countA; j++) {
			if (B[i] == A[j]) {
				BnotA[cBnA] = NULL;
				break;
			}
		}
		cBnA++;
	}
	
//	printf("A:\n");
//	for (int i = 0; i < countA; i++) {
//		printf("%d ", A[i]);
//	}
//	printf("\n");
//	
//	printf("B:\n");
//	for (int i = 0; i < countB; i++) {
//		printf("%d ", B[i]);
//	}
//	printf("\n");
	
	sortASC(AB, cAB);
	sortASC(AnotB, cAnB);
	sortASC(BnotA, cBnA);
	
	for (int i = 0; i < cAB; i++) {
		printf("%d ", AB[i]);
	}
	printf("\n");
	
	for (int i = 0; i < cAnB; i++) {
		if (AnotB[i] != NULL) {
			printf("%d ", AnotB[i]);
		}
	}
	printf("\n");
	
	for (int i = 0; i < cBnA; i++) {
		if (BnotA[i] != NULL) {
			printf("%d ", BnotA[i]);
		}
	}
	printf("\n");
}
