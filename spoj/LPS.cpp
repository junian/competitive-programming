#include <cstdio>

//bool p[100001][3];
int n=0;

//int linear_lps(char *s)
//{
//    int max=1;
//    int i,j;
//    for(i=0;i<n-1;i++)
//    {
//        p[i][0]=true;
//        if(s[i]==s[i+1])
//        {
//            p[i][1]=true;
//            max=2;
//        }
//        else
//            p[i][1]=false;
//    }
//    for(i=2;i<n;i++)
//    {
//        for(j=0;j<n-i+1;j++)
//        {
//            if(p[j+1][0] && s[j]==s[j+i-1])
//            {
//                p[j][2]=true;
//                max=i+1;
//            }
//            else p[j][2]=false;
//            p[j][0]=p[j][1];
//            p[j][1]=p[j][2];
//        }
//    }
//    return max;
//}

bool pal(char *a, char *b)
{
    while(a<b)
    {
        if(*a != *b)
            return false;
        a++;
        b--;
    }
    return true;
}

int main()
{
    char s[100001];
    int i,j,l=1;
    while(1)
    {
        n=0;
        while((s[0]=getchar())!='\n')
        {
            if(s[0]==EOF)
                return 0;
            n = (s[0]-'0')+n*10;
        }
        for(i=0;i<n;i++)
            s[i]=getchar();
        getchar();
        s[n]='\0';
        l=1;
        for(i=n-1;i>=1;i--)
        {
            for(j=0;j+i<n;j++)
                if(pal(&s[j],&s[j+i]))
                {
                    l=i+1;
                    i=0;
                    j=n+1;
                }
        }
        printf("%d\n",l);
    }
//    printf("%d\n",linear_lps(s));
    return 0;
}
