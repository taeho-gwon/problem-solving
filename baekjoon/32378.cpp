#include <bits/stdc++.h>

using namespace std;

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

// yes/no
void yes() { cout << "Yes\n"; }
void no() { cout << "No\n"; }
void yesno(bool x) { x ? yes() : no(); }

int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int n, k, s;
    cin >> n >> k >> s;
    vl a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    const ll MEGA = 100'000'000'000;
    const ll DEAD = -1LL << 60;
    if (k >= 37)
    {
        cout << "MEGA";
        return 0;
    }

    vvl dp(n + 1);
    dp[0].resize(k + 1, DEAD);
    dp[0][0] = s;
    for (int i = 1; i <= n; i++)
    {
        dp[i].resize(k + 1);
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j] + a[i - 1];
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] * 2);
            if (dp[i][j] <= 0)
                dp[i][j] = DEAD;
        }
    }

    ll ans = DEAD;
    for (int i = 0; i <= k; i++)
        ans = max(ans, dp[n][i]);
    if (ans == DEAD)
        cout << -1;
    else if (ans > MEGA)
        cout << "MEGA";
    else
        cout << ans;

    return 0;
}
