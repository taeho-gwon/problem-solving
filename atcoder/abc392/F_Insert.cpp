#include <bits/stdc++.h>
#include <atcoder/all>

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

int op(int x, int y)
{
    return x + y;
}
int e()
{
    return 0;
}
vi p;
int k;
bool f(int x)
{
    return x < k;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    segtree<int, op, e> a(n);
    for (int i = 0; i < n; i++)
        a.set(i, 1);
    vi ans(n);
    for (int i = n; i >= 1; i--)
    {
        k = p[i];
        int idx = a.max_right<f>(0);
        a.set(idx, 0);
        ans[idx] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
