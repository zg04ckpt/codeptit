#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	long long *x = (long long*)a;
	long long *y = (long long*)b;
	return *x > *y;
}

int kt(long long a[], int n) {
    // Tính bình phương
    for (int i = 0; i < n; i++) {
        a[i] *= a[i];
    }
    
    qsort(a, n, sizeof(long long), cmp);

    // Kiểm tra tam giác vuông
    for (int i = n - 1; i >= 2; i--) {
        int j = 0;
        int k = i - 1;
        while (j < k) {
            if (a[j] + a[k] == a[i]) {
                return 1;
            } else if (a[j] + a[k] < a[i]) {
                j++;
            } else {
                k--;
            }
        }
    }

    return 0;
}


int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int n;
		scanf("%d", &n);
		
		long long a[n];
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		
		if (kt(a, n)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
