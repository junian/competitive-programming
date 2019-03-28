#include<stdio.h>
#include<memory.h>
#define SIZE_N 1000100

typedef struct{
    int to;
    int vis;
    int next;
}SEdge;

SEdge eg[SIZE_N];
int stack[SIZE_N];
int Sys_sk[SIZE_N];
int head[SIZE_N/10];
int idx,top1,top2;

void Add_edge(int f,int t)
{
    eg[idx].to = t;
    eg[idx].next = head[f];
    eg[idx].vis = 0;
    head[f] = idx ++;
}
void DFS(int st)
{
    int i;
    top1 = top2 = 0;
    while( 1 ){
        for(i = st; i ;i = eg[i].next){
            if(!eg[i].vis){
                eg[i].vis = 1;
                Sys_sk[top1++] = i;
                st = head[eg[i].to];
                head[eg[i].to] = eg[head[eg[i].to]].next;
                break;
            }
        }
        if(!i){
            if(--top1 == -1)break;
            st = eg[Sys_sk[top1]].next;
            stack[top2++] = eg[Sys_sk[top1]].to % 10;
        }
    }
}
int main()
{
    int n;
    int num,mod;
    int i,j,tmp;
    while(scanf("%d",&n),n){
        if(n == 1){puts("0123456789");continue;}
        for(i = num = 1;i < n;i ++,num *= 10);
        mod = num / 10;
        memset(head, 0 ,sizeof(int)*num);
        idx = 1;
        for(i = 0;i < num;i ++){
            tmp = i % mod;
            tmp *= 10;
            for(j = 9;j >= 0;j --){
                Add_edge(i,tmp + j);
            }
        }
        DFS(head[0]);
        printf("%0*d",n-1,0);
        for(i = top2 - 1;i >= 0;i --)
            printf("%d",stack[i]);
        puts("");
    }
    return 0;
}
