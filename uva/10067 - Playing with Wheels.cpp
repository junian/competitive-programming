#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 10024


int make_num(int a, int b, int c, int d)
{
    return a*1000+b*100+c*10+d;
}

int arr_num(int nn[4])
{
    return make_num(nn[0],nn[1],nn[2],nn[3]);
}

int main()
{
    bool visited[MAX];
    int depth[MAX];

    int num[4];
    int angka,t,a,b,c,d,m,target;
    int curr_num,tmp;
    bool founded;

    scanf("%d",&t);
    while(t--)
    {
        memset(visited,0,sizeof(visited));
        memset(depth,0,sizeof(depth));
        scanf("%d%d%d%d",&num[0],&num[1],&num[2],&num[3]);
        scanf("%d%d%d%d",&a,&b,&c,&d);
        target = make_num(a,b,c,d);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            visited[make_num(a,b,c,d)] = true;
        }

        founded = false;
        curr_num = arr_num(num);
        if(curr_num == target)
            founded = true;
        else if(!visited[curr_num])
        {
            queue<int> q;

            q.push(curr_num);
            visited[curr_num] = true;
            depth[curr_num] = 0;
            while(!founded && !q.empty())
            {
    //            puts("aaaaaa");
                curr_num = q.front();
                q.pop();

                num[0] = curr_num/1000;
                num[1] = (curr_num%1000)/100;
                num[2] = (curr_num%100)/10;
                num[3] = (curr_num%10);

    //            printf("curr_num = %d\n",curr_num);

                for(int i=0;!founded && i<4;i++)
                {
                    num[i] = (num[i]+1)%10;
                    tmp = arr_num(num);
    //                printf("tmp = %d\n",tmp);
                    if(!visited[tmp])
                    {
                        visited[tmp] = true;
                        depth[tmp] = depth[curr_num]+1;
                        if(tmp == target)
                            founded = true;
                        q.push(tmp);
                    }
                    num[i] = (num[i]+9)%10;
                }

                for(int i=0;!founded && i<4;i++)
                {
                    num[i] = (num[i]+9)%10;
                    tmp = arr_num(num);
    //                printf("tmp = %d\n",tmp);
                    if(!visited[tmp])
                    {
                        visited[tmp] = true;
                        depth[tmp] = depth[curr_num]+1;
                        if(tmp == target)
                            founded = true;
                        q.push(tmp);
                    }
                    num[i] = (num[i]+1)%10;
                }
            }
        }
        if(founded)
            printf("%d\n",depth[target]);
        else
            puts("-1");
    }

    return 0;
}
