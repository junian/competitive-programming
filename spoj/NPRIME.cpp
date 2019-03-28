#include<cstdio>
int main(){
    int p[100001];
    int i,j,x=2,M=1299710;
    char a[M];p[1]=2;
    for(i=3;i<M;i+=2)
        a[i]=1;
    for(i=3;i<M;i+=2)
        if(a[i]==1){
            p[x++]=i;
            for(j=2*i;j<M;j+=i)
                a[j]=0;
        }
    while(scanf("%d",&i)!=-1)
        printf("%d\n",p[i]);
    return 0;
}
