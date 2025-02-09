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

mint997 dp[105][1100];

int n, m;
str s;

int nxt(int j, int c)
{
    vi dp(n + 1);
    int jj = j;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (jj & 1);
        jj >>= 1;
    }
    vi ndp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ndp[i] = max(ndp[i - 1], dp[i]);
        if (s[i - 1] == c + 'a')
            ndp[i] = max(ndp[i], dp[i - 1] + 1);
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret |= (ndp[i + 1] - ndp[i]) << i;
    }
    return ret;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cin >> n >> m >> s;
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            for (int k = 0; k < 26; k++)
            {
                dp[i + 1][nxt(j, k)] += dp[i][j];
            }
        }
    }

    vc<mint997> ans(n + 1);
    vi popcnt(1 << n);
    for (int i = 1; i < (1 << n); i++)
    {
        int lowbit = -i & i;
        popcnt[i] = popcnt[i ^ lowbit] + 1;
    }
    for (int i = 0; i < (1 << n); i++)
    {
        ans[popcnt[i]] += dp[m][i];
    }

    for (int i = 0; i <= n; i++)
    {
        cout << ans[i].val() << " ";
    }
    return 0;
}
