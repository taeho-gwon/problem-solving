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

mint998 pw(mint998 a, int b)
{
    mint998 ret = 1, x = a;
    while (b)
    {
        if (b % 2 == 1)
            ret *= x;
        b /= 2;
        x *= x;
    }
    return ret;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    vi a(n);
    for (int i = 1; i < n; i++)
        cin >> a[i];
    mint998 ans = 1;
    for (int p = 2; p <= 1000; p++)
    {
        vi dg(n);
        bool chk = false;
        for (int i = 1; i < n; i++)
        {
            while (a[i] % p == 0)
            {
                chk = true;
                dg[i]++;
                a[i] /= p;
            }
        }
        if (!chk)
            continue;

        vc<vc<mint998>> dp(n);
        dp[0].resize(1, 1);
        for (int i = 0; i < n - 1; i++)
        {
            dp[i + 1].resize(dp[i].size() + dg[i + 1]);
            for (int j = 0; j < dp[i].size(); j++)
            {
                if (dg[i + 1] == 0)
                {
                    dp[i + 1][j] += dp[i][j] * pw(p, j);
                    continue;
                }
                dp[i + 1][j + dg[i + 1]] += dp[i][j] * pw(p, j + dg[i + 1]);
                if (j >= dg[i + 1])
                {
                    dp[i + 1][j - dg[i + 1]] += dp[i][j] * pw(p, j - dg[i + 1]);
                }
                else
                {
                    dp[i + 1][0] += dp[i][j] * pw(p, (i + 1) * (dg[i + 1] - j));
                }
            }
        }
        mint998 nowsum = 0;
        for (mint998 v : dp[n - 1])
        {
            nowsum += v;
        }
        ans *= nowsum;
    }
    cout << ans.val();

    return 0;
}
