#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

vector<pii> half(const vector<int> &S)
{
    vector<pii> ans;
    int N = S.size();
    for (int i = 0; i < (1 << N); i++)
        for (int j = i; ; j = (j - 1) & i)
        {
            int sum = 0;
            for (int k = 0; k < N; k++)
            {
                if (j & (1 << k))
                    sum -= S[k];
                else if (i & (1 << k))
                    sum += S[k];
            }
            if (sum >= 0)
                ans.push_back(pii(sum, i));
            if (j == 0)
                break;
        }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    return ans;
}

int main()
{
    ifstream in("subsets.in");
    ofstream out("subsets.out");
    int N;
    in >> N;
    vector<int> SL, SR;
    for (int i = 0; i < N; i++)
    {
        int x;
        in >> x;
        if (i & 1)
            SL.push_back(x);
        else
            SR.push_back(x);
    }

    vector<pii> L = half(SL);
    vector<pii> R = half(SR);

    int p = 0;
    int q = 0;
    int LS = L.size();
    int RS = R.size();
    vector<bool> good(1 << N);
    while (p < LS && q < RS)
    {
        if (L[p].first < R[q].first)
            p++;
        else if (L[p].first > R[q].first)
            q++;
        else
        {
            int p2 = p;
            int q2 = q;
            while (p2 < LS && L[p2].first == L[p].first)
                p2++;
            while (q2 < RS && R[q2].first == R[q].first)
                q2++;
            for (int i = p; i < p2; i++)
                for (int j = q; j < q2; j++)
                {
                    good[L[i].second | (R[j].second << SL.size())] = true;
                }
            p = p2;
            q = q2;
        }
    }
    int ans = count(good.begin() + 1, good.end(), true);
    out << ans << endl;
}
