#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main() {
    int m, n, *a, *b, *c, *s, t, r, i, j, k, l, g, h, T;
    long long p, q;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &m, &n);
        m/=2;
        a=(int *)calloc(n+1, sizeof(int));
        b=(int *)malloc((n+1)*sizeof(int));
        s=(int *)calloc(n+1, sizeof(int));
        if (m%2) {
                for(g=i=0;i<10;l=i%n,a[l]++,g=g<l+1?l+1:g,i++);r=10%n;
                s[0]=1;
        } else {
                r=1%n;a[0]++;g=1;
        }
        m/=2;
        for(i=0;i<m;i++) {
                s[0]=0;
                memset(b, '\0', n*sizeof(int));t=(10*r+1)%n;
                for(h=j=0;j<10;j++) {
                    for(k=0;k<g;k++) {
                        if (a[k]) {
                            l=(j*t+10*k)%n;
                            b[l]+=a[k];
                            if(i==m-1&&j==0) s[l]+=a[k];
                            if(h<l+1) h=l+1;
                        }
                    }
                }
                c=a;a=b;b=c; r=(r*100)%n;
                g=h;
        }
        for(p=i=0;i<g;i++) {
            q = a[i]-s[i];
            q *= q ? a[(n-((i*r)%n))%n] : 1;
            p += q;
        }
        printf("%lld\n", p);
    }
    return 0;
}
