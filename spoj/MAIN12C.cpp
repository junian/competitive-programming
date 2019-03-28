#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    int t;
    char s[10032];
    pair<int, int> res[10032];
    int n;
    scanf("%d\n", &t);
    for(int tc=1;tc<=t;tc++)
    {
        n=0;
        gets(s);
        int len = strlen(s);
        int state = 0;
        //int len_user = 0;
        int at_p = 0;
        int start = 0;
        int end = 0;
        while(1){
            if(s[end] == '\0')
                break;
            if(state == 0){
                if(s[end] == '@' && end-start-1>=4)
                {
                    state++;
                    //len_user = end-start+1;
                    at_p = end;
                    end++;
                }
                else if((s[end] == '.' || s[end] == '_') && end-start>0)
                {
                    end++;
                }
                else if( (s[end]>='A' && s[end]<='Z') ||
                         (s[end]>='a' && s[end]<='z') ||
                         (s[end]>='0' && s[end]<='9'))
                {
                    end++;
                }
                else
                {
                    end++;
                    start = end;
                }
            }
            else if(state == 1){
                if(s[end] == '.' && end-start>at_p-start+1)
                {
                    state = 0;
                    if(end+3<len && ( (s[end+1] == 'c' && s[end+2] == 'o' && s[end+3] == 'm') ||
                                      (s[end+1] == 'o' && s[end+2] == 'r' && s[end+3] == 'g') ||
                                      (s[end+1] == 'e' && s[end+2] == 'd' && s[end+3] == 'u') )) //&&
//                                      (s[end+4] == ' ' || s[end+4]=='\0'))
//                        !((s[end+4]>='A' && s[end+4]<='Z') ||
//                          (s[end+4]>='a' && s[end+4]<='z') ||
//                          (s[end+4]>='0' && s[end+4]<='9') || 
//                           s[end+4] == '.'))
                    {
                        res[n++] = make_pair(start, end+3);
                        start = end + 4;
                        end = end + 4;
                    }
                    else if(end+5<len && s[end+1] == 'c' && s[end+2] == 'o' && s[end+3] == '.' && s[end+4] == 'i' && s[end+5] == 'n') //&&
//                            (s[end+6] == ' ' || s[end+6]=='\0'))
//                          !((s[end+6]>='A' && s[end+6]<='Z') ||
//                            (s[end+6]>='a' && s[end+6]<='z') ||
//                            (s[end+6]>='0' && s[end+6]<='9') ||
//                            s[end+6] == '.'))
                    {
                        res[n++] = make_pair(start, end+5);
                        start = end + 6;
                        end = end + 6;
                    }
                    else
                    {
                        //end = at_p+1;
                        end++;
                        start = at_p+1;
                    }
                }
                else if( (s[end]>='A' && s[end]<='Z') ||
                         (s[end]>='a' && s[end]<='z') ||
                         (s[end]>='0' && s[end]<='9'))
                {
                    end++;
                }
                else
                {
                    end++;
                    start = end;
                    state = 0;
                }
            }
        }
        printf("Case #%d: %d\n", tc, n);
        for(int i=0;i<n;i++)
        {
            for(int j=res[i].first;j<=res[i].second;j++)
                putchar(s[j]);
            puts("");
        }
    }
    return 0;
}
