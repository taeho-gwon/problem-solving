#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

// redef type
using ll = long long;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

template <class T>
using vc = vector<T>;

using vi = vc<int>;
using vl = vc<ll>;
using vs = vc<str>;
using vpi = vc<pi>;
using vpl = vc<pl>;
using vvi = vc<vi>;
using vvl = vc<vl>;
using vvpi = vc<vpi>;
using vvpl = vc<vpl>;

template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vc<T>, greater<T>>;

using mint998 = modint998244353;
using mint107 = modint1000000007;

// yes/no
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }
void yesno(bool x) { x ? yes() : no(); }

int n, x;
vpl v[4];
vvl dp[4];
vl dpmax[4];

int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        ll vv, aa, cc;
        cin >> vv >> aa >> cc;
        v[vv].push_back({aa, cc});
    }
    for (int i = 1; i <= 3; i++)
    {
        dp[i].resize(v[i].size() + 1);
        for (int j = 0; j <= v[i].size(); j++)
        {
            dp[i][j].resize(x + 1, -1);
            if (j == 0)
            {
                dp[i][j][0] = 0;
                continue;
            }
            for (int k = 0; k <= x; k++)
            {
                if (k >= v[i][j - 1].second)
                {
                    dp[i][j][k] = max(dp[i][j - 1][k], dp[i][j - 1][k - v[i][j - 1].second] + v[i][j - 1].first);
                }
                else
                    dp[i][j][k] = dp[i][j - 1][k];
            }
        }

        dpmax[i].resize(x + 1);
        dpmax[i][0] = dp[i][v[i].size()][0];

        for (int j = 1; j <= x; j++)
        {
            dpmax[i][j] = max(dpmax[i][j - 1], dp[i][v[i].size()][j]);
        }
    }

    ll a[4] = {0};
    for (int i = 0; i < x; i++)
    {
        int minidx = 1;
        for (int j = 2; j <= 3; j++)
        {
            if (dpmax[minidx][a[minidx]] > dpmax[j][a[j]])
                minidx = j;
        }
        a[minidx]++;
    }
    cout << min({dpmax[1][a[1]], dpmax[2][a[2]], dpmax[3][a[3]]});
    return 0;
}
