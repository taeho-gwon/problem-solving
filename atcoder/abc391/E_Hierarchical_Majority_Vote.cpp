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

using mint997 = modint998244353;
using mint107 = modint1000000007;

// yes/no
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }
void yesno(bool x) { x ? yes() : no(); }

int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    vvi one(n + 1), dp(n + 1);
    str s;
    cin >> s;
    one[n].resize(s.length());
    dp[n].resize(s.length());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            one[n][i] = 1;
        else
            one[n][i] = 2;
        dp[n][i] = 1;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int l = one[i + 1].size() / 3;
        one[i].resize(l);
        dp[i].resize(l);
        for (int j = 0; j < l; j++)
        {
            const int INF = 1 << 30;
            int dpsub[2][3] = {INF, INF, INF, INF, INF, INF};
            for (int k = 0; k < 3; k++)
            {
                one[i][j] += one[i + 1][3 * j + k] / 2;
                dpsub[one[i + 1][3 * j + k] / 2][k] = dp[i + 1][3 * j + k];
            }
            if (one[i][j] == 0)
            {
                int mx = max({dpsub[0][0], dpsub[0][1], dpsub[0][2]});
                dp[i][j] = dpsub[0][0] + dpsub[0][1] + dpsub[0][2] - mx;
            }
            else if (one[i][j] == 1)
            {
                dp[i][j] = min({dpsub[0][0], dpsub[0][1], dpsub[0][2]});
            }
            else if (one[i][j] == 2)
            {
                dp[i][j] = min({dpsub[1][0], dpsub[1][1], dpsub[1][2]});
            }
            else
            {
                int mx = max({dpsub[1][0], dpsub[1][1], dpsub[1][2]});
                dp[i][j] = dpsub[1][0] + dpsub[1][1] + dpsub[1][2] - mx;
            }
        }
    }
    cout << dp[0][0];
    return 0;
}
