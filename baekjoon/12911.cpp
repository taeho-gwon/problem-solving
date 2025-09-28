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

const int K = 101010;
const int MOD = 1000000007;
int dp[11][K], dp_kmul[11][K];
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        dp[1][i] = 1;
        dp_kmul[1][i] = k / i - 1;
    }
    int psum = k;
    for (int i = 2; i <= n; i++)
    {
        int npsum = 0;
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = (psum - dp_kmul[i - 1][j] + MOD) % MOD;
            npsum = (npsum + dp[i][j]) % MOD;
        }
        for (int j = 1; j <= k; j++)
        {
            for (int s = j * 2; s <= k; s += j)
                dp_kmul[i][j] = (dp_kmul[i][j] + dp[i][s]) % MOD;
        }
        psum = npsum;
    }
    cout << psum;
}
