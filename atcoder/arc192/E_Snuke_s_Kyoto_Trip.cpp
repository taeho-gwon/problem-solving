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

const int N = 1000005;
mint998 fac[N * 2];

mint998 g(int p, int q)
{
    return fac[p + q + 4] / fac[p + 2] / fac[q + 2] - (mint998)(p + 2) * (mint998)(q + 2) - 1;
}
mint998 f(int p, int q)
{
    return fac[p + q + 2] / fac[p + 1] / fac[q + 1] - 1;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int w, h, l, r, d, u;
    cin >> w >> h >> l >> r >> d >> u;
    fac[0] = 1;
    for (int i = 1; i < 2 * N; i++)
    {
        fac[i] = fac[i - 1] * i;
    }

    mint998 ans = g(w, h) - g(r - l, u - d);
    for (int i = l; i <= r; i++)
    {
        ans -= f(i, d - 1) * f(w - i, h - d);
        ans -= f(i - l, u - d) * f(w - i, h - u - 1);
    }
    for (int i = d; i <= u; i++)
    {
        ans -= f(l - 1, i) * f(w - l, h - i);
        ans -= f(r - l, i - d) * f(w - r - 1, h - i);
    }
    cout << ans.val();
    return 0;
}
