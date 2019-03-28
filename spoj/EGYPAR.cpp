#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 10032
#define pii pair<double,int>
template<typename T>
T getNum()
{
            T res = 0;   
                  char c;
                  while(1)
                  {
                                  c=getchar_unlocked();
                                  if(c==' ' || c=='\n')continue;
                                  else break;
                  }
                  res= c - '0';
                  while(1)
                  {
                                  c = getchar_unlocked();
                                  if(c>='0' && c<='9')res=10*res + c-'0';
                                  else if(c==',') continue;
                                  else break;
                  }
                  return res;
}

int sainte[MAX];
int dhondt[MAX];
double quoSainte[MAX];

int sainteACM;
int dhondtACM;
int indexACM;

char party[MAX][32];
int vote[MAX];

int main()
{
    int T,P,S;
    T = getNum<int>();
    for(int tc=1;tc<=T;tc++)
    {
        //pq.clear();
        priority_queue<pii, vector<pii>, less<pii> > pq;
        priority_queue<pii, vector<pii>, less<pii> > pqs;
        sainteACM = dhondtACM=0;
        indexACM = -1;
        P = getNum<int>();
        S = getNum<int>();
        for(int i=0;i<P;i++)
        {
            scanf("%s", party[i]);
            vote[i] = getNum<int>();
            if(indexACM<0 && strcmp(party[i],"ACM")==0)
                indexACM = i;
            sainte[i] = 0;
            dhondt[i] = 0;
        }
        
        //sainte
        
        //while(!pqs.empty())
        //    pqs.pop();
            
        for(int i=0;i<P;i++){
            pqs.push(make_pair((double) vote[i], i));
        }
        
        for(int j=0;j<S;j++)
        {
            pii p = pqs.top();
            pqs.pop();
            sainte[p.second]++;
            pqs.push(make_pair( ((double) vote[p.second])/(2.0*(double)sainte[p.second]+1.0), p.second));
        }
        
        //dhondt
        //while(!pq.empty())
        //    pq.pop();
        for(int i=0;i<P;i++)
            pq.push(make_pair((double)vote[i], i));
        
        
        for(int j=0;j<S;j++)
        {
            pii p = pq.top();
            dhondt[p.second]++;
            pq.pop();
            pq.push(make_pair(((double)vote[p.second])/(double) (dhondt[p.second]+1), p.second));
        }

        printf("Case %d: ",tc);
        if(sainte[indexACM]>dhondt[indexACM])
            puts("S");
        else if(sainte[indexACM]<dhondt[indexACM])
            puts("D");
        else
            puts("No difference");
    }
    return 0;
}
