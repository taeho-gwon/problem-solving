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

    int n, m;
    cin >> n >> m;
    vs s(n + 1), t(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> t[i];
        t[i] = " " + t[i];
    }
    for (int i = 1; i <= n - m + 1; i++)
    {
        for (int j = 1; j <= n - m + 1; j++)
        {
            bool chk = true;
            for (int k = 1; chk && k <= m; k++)
            {
                for (int r = 1; chk && r <= m; r++)
                {
                    if (s[i + k - 1][j + r - 1] != t[k][r])
                        chk = false;
                }
            }
            if (chk)
            {
                cout << i << " " << j;
                return 0;
            }
        }
    }

    return 0;
}
