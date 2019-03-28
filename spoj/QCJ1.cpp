#include <cstdio>
int main()
{
    char a[21][201];
    int n,i,j,tot,t;
    char c;
    scanf("%d",&n);
    t=0;
    fflush(stdin);
    gets(a[0]);
    //while( (c = getchar() ) != '\n');
    //while( (c = getchar() ) != '\n');
    for(i=1;i<=n;i++)
    {
        gets(a[i]);
        for(j=0;a[i][j]!='\0';j++)
            if(a[i][j]!=' ')t++;
    }
    printf("Total Walk Distance = %d\n", t);
    i=n;
    j=0;
    while(!(i==n && j==t))
    {
        tot=0;
        switch(a[i][j])
        {
            case '/':
                while(1)
                {
                    tot++;
                    if(i-1>=1 && a[i-1][j+1]=='/')
                    {
                        i--;j++;
                    }
                    else if(i-1>=1 && a[i-1][j+1]=='_')
                    {
                        i--;j++;
                        break;
                    }
                    else if(a[i][j+1]=='\\')
                    {
                        j++;
                        break;
                    }
                    else
                    {
                        j=t;
                        break;
                    }
                }
                printf("Up %d steps\n", tot);
                break;
            case '\\':
                while(1)
                {
                    tot++;
                    if(i+1<=n && a[i+1][j+1]=='\\')
                    {
                        i++;j++;
                    }
                    else if(a[i][j+1]=='_')
                    {
                        j++;
                        break;
                    }
                    else if(a[i][j+1]=='/')
                    {
                        j++;
                        break;
                    }
                    else
                    {
                        j=t;
                        break;
                    }

                }
                printf("Down %d steps\n", tot);
                break;
            case '_':
                while(1)
                {
                    tot++;
                    if(a[i][j+1]=='_')
                    {
                        j++;
                    }
                    else if(a[i][j+1]=='/')
                    {
                        j++;
                        break;
                    }
                    else if(i+1<=n && a[i+1][j+1]=='\\')
                    {
                        j++;i++;
                        break;
                    }
                    else
                    {
                        j=t;
                        break;
                    }
                }
                printf("Walk %d steps\n", tot);
                break;
            default:
                break;
        }

    }
    return 0;
}
