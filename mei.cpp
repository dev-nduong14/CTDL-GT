#include <stdio.h>
#include <stdlib.h>
int *c, *cc, *cp;
int a[100];
int n;
long long cl = 1;
void backtrack(int i) {
    if (i == n){
    	printf("db %lld\n",cl++);
        for (int m = 0;m < n; m++) {
            for (int k = 0; k < n; k++) {
                if (a[m] == k)
                    printf(" Q ");
                else
                    printf(" . ");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    for (int j = 0; j < n; j++) {
        if (!c[j] && !cc[i-j+n-1] && !cp[i+j]) {
            a[i] = j;
            c[j] = cc[i-j+n-1] = cp[i+j] = 1;
            backtrack(i + 1);
            c[j] = cc[i-j+n-1] = cp[i+j] = 0;
        }
    }
}

int main() {
    scanf("%lld", &n);
    c = (int *)calloc(n, sizeof(int));             
    cc = (int *)calloc(2 * n, sizeof(int));    
    cp = (int *)calloc(2 * n, sizeof(int));    
    backtrack(0);
    return 0;
}

