#include <cstdio>
#include <cstring>

int main()
{
    char w[1001];
    int t,l,a,m,c;
    char *x;
    scanf("%d", &t);
    fflush(stdin);
    while(t-->0)
    {

        a=0;
        m=0;
        c=0;
        gets(w);
        x=strchr(w,'\t');
        while (x!=NULL)
        {
            *x=' ';
            x=strchr(x+1,'\t');
        }
        x=strchr(w,'\r');
        while (x!=NULL)
        {
            *x=' ';
            x=strchr(x+1,'\r');
        }
        x = strtok (w," ");
        while (x!= NULL)
        {
            l=strlen(x);
            if(l!=0 && l!=a)
            {
                a=l;
                if(m<c)
                    m=c;
                c=0;
            }
            c++;
            x = strtok (NULL, " ");
        }
        if(m<c)
            m=c;
        printf("%d\n", m);
    }
    return 0;
}
