#include <cstdio>

long n,m;
long father[130011]={0};
long left[130011]={0};
long right[130011]={0};
char rev[130011]={0};
long count[130011]={0};
long root;
long size=0;

void updata(long x)
{
     count[x]=1;
     if(left[x])
      count[x]+=count[left[x]];
     if(right[x])
      count[x]+=count[right[x]];
}

void zig(long x)
{
     long y=father[x];
     left[y]=right[x];
     if(right[x]) father[right[x]]=y;
     father[x]=father[y];
     if(father[y])
     {
      if(y==left[father[y]]) left[father[y]]=x;
      else                   right[father[y]]=x;
     }
     right[x]=y;
     father[y]=x;
     updata(y);
     updata(x);
}

void zag(long x)
{
     long y=father[x];
     right[y]=left[x];
     if(left[x]) father[left[x]]=y;
     father[x]=father[y];
     if(father[y])
     {
      if(y==left[father[y]]) left[father[y]]=x;
      else                   right[father[y]]=x;
     }
     left[x]=y;
     father[y]=x;
     updata(y);
     updata(x);
}

void splay(long x,long y)
{
     while(1)
     {
        if(father[x]==y) break;
        if(father[father[x]]==y)
        {
           if(x==left[father[x]]) zig(x);
           else                   zag(x);
        }
        else
        {
           if(x==left[father[x]])
           {
             if(father[x]==left[father[father[x]]])
             {
               zig(father[x]);
               zig(x);
             }
             else
             {
               zig(x);
               zag(x);
             }
           }
           else
           {
             if(father[x]==left[father[father[x]]])
             {
               zag(x);
               zig(x);
             }
             else
             {
               zag(father[x]);
               zag(x);
             }
           }
        }
     }
     if(father[x]==0) root=x;
}

void insert(long x)
{
     long cur=root;
     while(1)
     {
         if(x<cur)
         {
             if(left[cur]==0)
             {
                 size++;
                 count[size]=1;
                 father[size]=cur;
                 left[cur]=size;
                 break;
             }
             else cur=left[cur];
         }
         else
         {
             if(right[cur]==0)
             {
              size++;
              count[size]=1;
              father[size]=cur;
              right[cur]=size;
              break;
           }
           else
              cur=right[cur];
        }
     }
     splay(size,0);
}

long rank(long x)
{
     long cur=root,tmp;
     while(1)
     {
        if(rev[cur])
        {
           rev[cur]=0;
           tmp=left[cur]; left[cur]=right[cur]; right[cur]=tmp;
           if(left[cur]) rev[left[cur]]=1-rev[left[cur]];
           if(right[cur])rev[right[cur]]=1-rev[right[cur]];
        }
        if(x==count[left[cur]]+1) break;
        if(x<=count[left[cur]])
          cur=left[cur];
        else
        {
          x-=(count[left[cur]]+1);
          cur=right[cur];
        }
     }
     return cur;
}

void revers(long x,long y)
{
     long i;
     x--;
     x=rank(x);
     y++;
     y=rank(y);
     splay(x,0);
     splay(y,x);
     if(left[y])rev[left[y]]=1-rev[left[y]];
}

void watch(long x)
{
     long cur,tmp;
     father[0]=1; father[1]=x;  count[x]=0;
     while(father[0])
     {
         cur=father[father[0]];
         if(count[cur])
         {
             if(cur!=1&&cur!=n+2)printf("%ld ",cur-1);
             father[0]--;
         }
         else
         {
             father[0]--;
             if(rev[cur])
             {
                 rev[cur]=0;
                 tmp=left[cur];
                 left[cur]=right[cur];
                 right[cur]=tmp;
                 if(left[cur])rev[left[cur]]=1-rev[left[cur]];
                 if(right[cur])rev[right[cur]]=1-rev[right[cur]];
             }
             if(right[cur])
             {
                 count[right[cur]]=0;
                 father[++father[0]]=right[cur];
             }
             father[++father[0]]=cur; count[cur]=1;
             if(left[cur])
             {
                 count[left[cur]]=0;
                 father[++father[0]]=left[cur];
             }
         }
     }
}

void read()
{
     long i,a,b;
     scanf("%ld%ld",&n,&m);
     root=1;  size=1;
     for(i=1;i<=n;i++)insert(i+1);
     insert(n+2);
     for(i=1;i<=m;i++)
     {
         scanf("%ld%ld",&a,&b);
         revers(a+1,b+1);
     }
     watch(root);
     printf("\n");
}

int main()
{
    read();
    return 0;
}
