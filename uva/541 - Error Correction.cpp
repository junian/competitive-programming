#include <cstdio>
int main()
{
    int m[100][100];
    int n,i,j,b,c,r,cc,rr;
    while(1)
    {
        scanf("%d",&n);
        if(n<=0)
            break;
        r=0;c=0;cc=0;rr=0;
        for(i=0;i<n;i++)
        {
            b=0;
            for(j=0;j<n;j++)
            {
                scanf("%d",&m[i][j]);
                b+=m[i][j];
            }
            if(b%2==1)
            {
                r=i+1;
                rr++;
            }
        }
        for(j=0;j<n;j++)
        {
            b=0;
            for(i=0;i<n;i++)
                b+=m[i][j];
            if(b%2==1)
            {
                c=j+1;
                cc++;
            }

        }
        if(c==0 && r==0)
            printf("OK\n");
        else if(c>0 && r>0 && cc==1 && rr==1)
            printf("Change bit (%d,%d)\n",r,c);
        else
            printf("Corrupt\n");
    }
    return 0;
}
