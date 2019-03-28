#include <iostream>
using namespace std;
int tree[400001][3], inc[400001];
void init(int seg, int low, int high) {
    tree[seg][0]=high-low+1;
    if (low<high) {
        int mid = (low+high)/2;
        init(2*seg,low,mid);
        init(2*seg+1,mid+1,high);
    }
}
void update(int seg, int low, int high, int a, int b) {
    // do we have 0 overlap
    if (b<low || a>high) return;
    // do we have full overlap
    if (a<=low && high<=b) {
        inc[seg]=(inc[seg]+1)%3;
        //printf("Incrementing segment %d\n",seg);
        return;
    }
    int mid = (low+high)/2;
    update(2*seg,low,mid,a,b);
    update(2*seg+1,mid+1,high,a,b);
    //printf("Tree[%d] = ",seg);
    for (int i=0; i<3; i++) {
        tree[seg][i] = tree[2*seg][(i+3-inc[2*seg])%3] + tree[2*seg+1][(i+3-inc[2*seg+1])%3];
        //printf("%d ",tree[seg][i]);
    }
    //printf("\n");
}
void query(int seg, int low, int high, int a, int b, int ret[3]) {
    //printf("CAllling query[%d][%d][%d][%d][%d]\n",seg,low,high,a,b);
    // 0 overlap
    if (b<low || a>high) {ret[0]=ret[1]=ret[2]=0;return;}
    // full overlap
    if (a<=low && high<=b) {
        //printf("Full segment %d\n",seg);
        int incs = 0;
        for (int k=seg; k>=1; k/=2) incs = (incs+inc[k])%3;
        //printf("Total inc was %d\n",incs);
        //printf("Returning");
        for (int i=0; i<3; i++) {
            ret[i] = tree[seg][(i+3-incs)%3];
            //printf(" %d",ret[i]);
        }
        //printf("\n");
        return;
    }
    int mid = (low+high)/2;
    int ret1[3] = {0,0,0};
    int ret2[3] = {0,0,0};
    query(2*seg,low,mid,a,b,ret1);
    query(2*seg+1,mid+1,high,a,b,ret2);
    //printf("querying from %d to %d (seg %d) returns: ",low,high,seg);
    for (int i=0; i<3; i++) {
        ret[i] = ret1[i] + ret2[i];
        //printf("%d ",ret[i]);
    }
    //printf("\n");
}
int main() {
    int N,Q; scanf("%d %d",&N,&Q);
    init(1,0,N-1);
    for (int i=0; i<Q; i++) {
        int a,b,c; scanf("%d %d %d",&a,&b,&c);
        if (a==0) update(1,0,N-1,b,c);
        else {
            int ret[3] = {0,0,0};
            query(1,0,N-1,b,c,ret);
            printf("%d\n",ret[0]);
        }
    }
}

