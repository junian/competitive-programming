#include <cstdio>

#define ll long long int

ll count(ll num){
    ll cnt = 0L;
    for(ll i=369L; i<=num;i++){
        ll n = i;
        ll s3= 0L;
        ll s6 = 0L;
        ll s9 = 0L;
        while(n>0){
            int mod = n%10;
            n/=10;
            if(mod == 3)
                s3++;
            else if(mod == 6)
                s6++;
            else if(mod == 9)
                s9++;
        }
        if(s3>0 && s3==s6 && s6==s9)
            cnt++;
    }
    return cnt;
}

int main(){
    ll n;
    while(1){
        scanf("%lld", &n);
        printf("%lld\n", count(n));
        
    }
    return 0;
}
