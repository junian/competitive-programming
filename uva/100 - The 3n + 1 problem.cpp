#include <cstdio>

int getMaxLength(int i, int j);
int cycleLength(int n);

int main() {
    long long i = 0;
    int j = 0;

    while(scanf("%lld%d",&i,&j)!=EOF) {
        printf("%lld %d %d\n",i,j,getMaxLength(i, j));
    }

    return 0;
}

int cycleLength(int n) {
    if(n<1) return 0;

    int length = 1;

    while(n!=1){
        if(n%2 != 0)
            n = 3*n + 1;
        else
            n = n / 2;
        length++;
    }

    return length;
}

int getMaxLength(int i, int j) {
    int length = 0;
    int maxLength = 0;

    if(i<j) {
        for(i=i; i<=j; i++) {
            length = cycleLength(i);
            if(maxLength < length)
                maxLength = length;
        }
    }
    else {
        for(j=j; j<=i; j++) {
            length = cycleLength(j);
            if(maxLength < length)
                maxLength = length;
        }
    }

    return maxLength;
}
