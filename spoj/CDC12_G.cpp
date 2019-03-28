#include <cstdio>
//#include <queue>
#include <algorithm>

using namespace std;

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
                                  else break;
                  }
                  return res;
}

const int dl[3] = {0,-1,1},
          dr[4] = {-1, 0, 0, 1}, 
          dc[4] = { 0,-1, 1, 0};
          
const int MAX = 21,
          ENMAX = 11,
          STATE = 1<<ENMAX,
          QMAX = 27800,
          INF = 2000000000;
          
int dist[MAX][MAX][MAX], L, R, C, tot;
int ddist[ENMAX][ENMAX];
int dp[STATE][ENMAX];
int er[ENMAX],ec[ENMAX],el[ENMAX];
char grid[MAX][MAX][MAX];

int Q[QMAX];
int front, back;

void bfs(int ui, int uj, int uk) 
{
    for(int l=0;l<L;l++)
    	for(int i=0; i<R; i++)
			for(int j=0; j<C; j++)
				dist[l][i][j] = INF;
					
	int vi, vj, vk;
	front = back = 0;
	//queue< int > Q;
	
    dist[ui][uj][uk] = 0;
	
    //Q.push(ui);
    //Q.push(uj);
    //Q.push(uk);
	Q[back++] = ui;
	Q[back++] = uj;
	Q[back++] = uk;
	
    //while(!Q.empty()) 
    while(front<back)
    {
		//ui = Q.front(); Q.pop();
		//uj = Q.front(); Q.pop();
		//uk = Q.front(); Q.pop();
		ui = Q[front++];
		uj = Q[front++];
		uk = Q[front++];
		
        for(int i=0; i<4; i++) 
        {
            for(int l=0;l<3;l++)
            {
    			vi = ui + dl[l];
                vj = uj + dr[i];
                vk = uk + dc[i];
                
    			if(vi>=0 && vi<L && vj>=0 && vj<R && vk>=0 && vk<C && dist[vi][vj][vk]==INF && grid[vi][vj][vk]!='#') 
                {
					dist[vi][vj][vk] = dist[ui][uj][uk] + 1;
					
                    //Q.push(vi);
                    //Q.push(vj);
                    //Q.push(vk);
    				Q[back++] = vi;
                	Q[back++] = vj;
                	Q[back++] = vk;
    			}
            }
		}
	}
}

int f(int mask, int st){
	int res = dp[mask][st];
	
	if (res!=-1)
        return res;
        
	res = INF;
	bool oke = false;
	
	for (int i=0; i<tot; ++i){
        if (i!=st && (mask & (1<<i))) {
		  oke = true;
		  res = min(res, f(mask^(1<<st),i)+ddist[i][st]);
	    }
    }
	
	if (!oke)
        res=0;
	dp[mask][st] = res;
	return res;
}

int main() 
{
	int i, j, k, si, sj, t;
	//scanf("%d", &t);
	t = getNum<int>();
	for(int tc=1;tc<=t;tc++) {
        //scanf("%d%d", &C, &L);
        C = getNum<int>();
        L = getNum<int>();
        R = C;
        tot = 0;
        for(int l=0;l<L;l++)
        {
    		for(i=0; i<R; i++) {
    			//scanf("%s", grid[ii][i]);
    			for(j=0; j<C; j++) {
                    grid[l][i][j] = getchar_unlocked();
    				if(grid[l][i][j]=='*')
    				{
                        el[tot] = l;
                        er[tot] = i;
                        ec[tot++] = j;
                    }
    			}
    			getchar_unlocked();
    		}
        }
        bfs(0,0,0);
        for(int i=0;i<tot;i++)
            ddist[tot][i] = dist[el[i]][er[i]][ec[i]];
        for (int i=0; i<tot; i++) {
			bfs(el[i],er[i],ec[i]);
			for (int j=0; j<tot; j++)
                ddist[i][j] = dist[el[j]][er[j]][ec[j]];
		}
		
		for (int i=0; i<(1<<tot); i++)
            for (int j=0; j<tot; j++)
                dp[i][j]=-1;
		
		int res = INF;
		
		for (int i=0; i<tot; ++i)
			res = min(res, f((1<<tot)-1,i)+ddist[tot][i]);
		
        res = res == INF ? -1 : res;	
		printf("Scenario #%d: %d\n", tc, res);
	}
	return 0;
}
