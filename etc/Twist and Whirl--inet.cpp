#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N=135555;
int n,m,root;
int ch[N][2];
int pre[N];
int key[N];
int rev[N];
int Size[N];

void build(){
    Size[0]=0;
    for (int i=n+2;i>=1;i--){
        key[i]=i;
        rev[i]=0;
        Size[i]=n+3-i;
        if (i<=n+1) ch[i][1]=i+1;
        pre[i]=i-1;
    }
    root=1;
}

void pushdown(int x){
    if (!x) return;
    if (rev[x]){
        rev[x]=0;
        if (ch[x][0]) rev[ch[x][0]]^=1;
        if (ch[x][1]) rev[ch[x][1]]^=1;
        swap(ch[x][0],ch[x][1]);
    }
}

void update(int x){
    if (!x) return;
    pushdown(x);
    pushdown(ch[x][0]);
    pushdown(ch[x][1]);
    Size[x]=Size[ch[x][0]]+Size[ch[x][1]]+1;
}

void rotate(int x,int T){
    int y=pre[x];
    pushdown(y);
    pushdown(x);
    if (T){
        ch[y][0]=ch[x][1];
        ch[x][1]=y;
        pre[ch[y][0]]=y;
    }
    else{
        ch[y][1]=ch[x][0];
        ch[x][0]=y;
        pre[ch[y][1]]=y;
    }
    pre[x]=pre[y];
    pre[y]=x;
    if (ch[pre[x]][0]==y) ch[pre[x]][0]=x;
                     else ch[pre[x]][1]=x;
    update(y);
    update(x);
}

void Splay(int x,int goal){
    if (x==goal) return;
    if (!goal) root=x;
    int y,z;
    while (pre[x]!=goal){
        y=pre[x]; z=pre[y];
        if (z==goal) rotate(x,ch[y][0]==x);
        else
        if (ch[z][0]==y)
          if (ch[y][0]==x) {rotate(y,1); rotate(x,1);}
                      else {rotate(x,0); rotate(x,1);}
        else
          if (ch[y][1]==x) {rotate(y,0); rotate(x,0);}
                      else {rotate(x,1); rotate(x,0);}
    }
}

int Rank(int k){
    int done=0,x=root;
    for (;;){
      update(x);
      if (done+Size[ch[x][0]]+1==k) return x;
      if (done+Size[ch[x][0]]+1< k){
          done+=Size[ch[x][0]]+1;
          x=ch[x][1];
      }
      else  x=ch[x][0];
    }
}

void output(){
    int i,x;
    for (i=2;i<=n+1;i++){
        //x=Rank(i);
        //Splay(x,0);
        printf("%d ",key[i]-1);
        //if (i==n+1) puts("");
               //else putchar(' ');
    }
    puts("");
    for (i=2;i<=n+1;i++){
        x=Rank(i);
        Splay(x,0);
        printf("%d",key[x]-1);
        if (i==n+1) puts("");
               else putchar(' ');
    }
}

void work(){
    for (int i=1;i<=m;i++){
        int l,r,x,y;
        scanf("%d%d",&l,&r);
        output();
        x=Rank(l);
        y=Rank(r+2);
        Splay(x,0);
        Splay(y,x);
        rev[ch[y][0]]^=1;
    }
}



int main(){
    scanf("%d%d",&n,&m);
    build();
    work();
    output();
}

