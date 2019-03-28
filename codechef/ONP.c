#include <stdio.h>
#include <string.h>

int priority(char c)
{
    switch(c)
    {
        case '+':
            return 1;
            break;
        case '-':
            return 2;
            break;
        case '*':
            return 3;
            break;
        case '/':
            return 4;
            break;
        case '^':
            return 5;
            break;
        default:
            break;

    }
    return 0;
}

int main()
{
    int t, l, ts, r, i;
    char exp[401];
    char res[401];
    char stack[401];
    scanf("%d", &ts);
    while(ts>0)
    {
        ts--;
        scanf("%s", exp);
        t = -1;
        r = 0;
        l = strlen(exp);
        for(i=0; i<l; i++)
        {
            if(exp[i]>='a' && exp[i]<='z')
            {
                res[r] = exp[i];
                r++;
            }
            else if(exp[i] == ')')
            {
                while(stack[t] != '(')
                {
                    res[r] = stack[t];
                    r++;
                    t--;
                }
                t--;
            }
            else if(t < 0 || priority(exp[i]) >= priority(stack[t]) ||
                        exp[i] == '(')
            {
                t++;
                stack[t] = exp[i];
            }
            else
            {
                while(t>=0 && stack[t] != '(')
                {
                    res[r] = stack[t];
                    r++;
                    t--;
                }
                t++;
                stack[t] = exp[i];
            }
        }
        while(t>=0)
        {
            res[r] = stack[t];
            r++;
            t--;
        }
        res[r] = '\0';
        printf("%s\n", res);
    }
    return 0;
}
