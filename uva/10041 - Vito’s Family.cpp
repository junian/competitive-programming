#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vect;
    int r, t, s, d;

    scanf("%d", &t);
    while(t>0)
    {
        t--;
        scanf("%d", &r);
        vect.clear();
        for(int i=0; i<r; i++)
        {
            scanf("%d", &s);
            vect.push_back(s);
        }
        sort(vect.begin(), vect.end());
        d=0;
        for(int i=r-1; i>=0; i--)
        {
            if(vect.at(r/2)>vect.at(i))
                d += vect.at(r/2) - vect.at(i);
            else
                d += vect.at(i) - vect.at(r/2);
        }
        printf("%d\n", d);
    }
    return 0;
}
