#include <stdio.h>

int check1(int b[]) {
	for (int i = 1; i < 5; i++) {
		if (b[i] <= b[i - 1]) {
			return 0;
		}
	}
			
	return 1;
}

int check2(int b[]) {
	for (int i = 1; i < 5; i++) {
		if (b[i] != b[i - 1]) {
			return 0;
		}            
	}
	
	return 1;
}

int check3(int b[]) {
	for (int i = 2; i < 3; i++) {
		if (b[i] != b[i - 1]) {
			return 0;
		}
	}
	
	if (b[3] != b[4]) {
		return 0;
	}
	
	return 1;
}
              
int check4(int b[]) {
	for (int i = 0; i < 5; i++) {
		if (b[i] != 6 && b[i] != 8) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int t; 
	scanf("%d",&t); 
	getchar(); 
	while(t--){ 
		char c[20]; 
		gets(c);
        
//		for (int i = 0; i < 13; i++) {
//			printf("%c", a[i]);
//		}

		int b[5];
		b[4] = c[11] - '0';
		b[3] = c[10] - '0';
		b[2] = c[8] - '0';
		b[1] = c[7] - '0';
		b[0] = c[6] - '0';
		
//		for (int i = 0; i < 5; i++) {
//			printf("%d ", b[i]);
//		}
//		
		if (check1(b) || check2(b) || check3(b) || check4(b)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
