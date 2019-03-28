#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int fakt[11] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    string kal;
    char temp;
    int n, max, c, l;
    vector<string> kumpulan;
    cin >> n;

    while(n>0)
    {
        n--;
        cin >> kal;
        l = kal.size();
        max = fakt[l];
        c = 0;
        kumpulan.clear();

        for(int i=0; i<max; i++)
        {
            temp = kal[c];
            kal[c] = kal[c+1];
            kal[c+1] = temp;
            kumpulan.push_back(kal);
            c = (c+1)%(l-1);
        }

        sort(kumpulan.begin(), kumpulan.end());
        unique(kumpulan.begin(), kumpulan.end());
        for(int i=0; i<kumpulan.size(); i++)
            cout << kumpulan[i] << endl;
        cout << endl;
    }

    return 0;
}
