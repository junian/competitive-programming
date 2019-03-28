#include<cstdio>
int main()
{
    char s[32];
    int h,m,d,c,t;
    while(scanf("%s",s)!=EOF)
    {
        t = 0;
        h = (s[0]-'0')*10 + (s[1]-'0');
        t += h*360000;
        m = (s[2]-'0')*10 + (s[3]-'0');
        t += m*6000;
        d = (s[4]-'0')*10 + (s[5]-'0');
        t += d*100;
        c = (s[6]-'0')*10 + (s[7]-'0');
        t += c;
//        c = t%100;
//        t = t/100;
//        d = t%100;
//        t = t/100;
//        m = t%100;
//        t = t/100;
        printf("%d\n",t);
    }
    return 0;
}
