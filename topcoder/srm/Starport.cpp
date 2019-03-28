#include <algorithm>
#include <cstdio>
using namespace std;

class Starport
{
    public:
        double getExpectedTime(int N, int M)
        {
            int g = __gcd(N,M);
            g = N/g;
            int a=M,b=N;
            double d = 0.0;
            while(a!=b)
            {
                while(a>b)
                    b += N;
                d += (double) (b-a);
                a += M;
            }
            return (d/g);
        }
};

int main()
{
    Starport a;
    printf("%lf\n",a.getExpectedTime(4,2));
    printf("%lf\n",a.getExpectedTime(5,3));
    printf("%lf\n",a.getExpectedTime(6,1));
    printf("%lf\n",a.getExpectedTime(12345,2345));
    return 0;
}
