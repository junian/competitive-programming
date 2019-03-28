
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class LuckyCounter
{
    public:
        int countLuckyMoments(vector <string> moments)
        {
            int i;
            int count = 0;
            for(i=0;i<moments.size();i++)
            {
                if((moments[i].at(0)==moments[i].at(3) && moments[i].at(1)==moments[i].at(4)) ||
                   (moments[i].at(0)==moments[i].at(1) && moments[i].at(3)==moments[i].at(4)) ||
                   (moments[i].at(0)==moments[i].at(4) && moments[i].at(1)==moments[i].at(3)))
                   count++;
            }
            return count;
        }
};

int main()
{
    LuckyCounter lc;
    vector<string> a;
    a.push_back("11:00");
    a.push_back("12:00");
    printf("%d\n",lc.countLuckyMoments(a));
    return 0;
}
