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

struct S
{
    ll zero, one, inv;
};
S op(S p, S q)
{
    return S{p.zero + q.zero, p.one + q.one, p.inv + q.inv + p.one * q.zero};
}
S e()
{
    return S{0, 0, 0};
}

S mapping(bool f, S p)
{
    if (f)
    {
        return S{p.one, p.zero, (ll)p.zero * p.one - p.inv};
    }
    else
        return p;
}
bool composition(bool f, bool g)
{
    return f ^ g;
}
bool id()
{
    return false;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    lazy_segtree<S, op, e, bool, mapping, composition, id> ls(n);

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 0)
            ls.set(i, {1, 0, 0});
        else
            ls.set(i, {0, 1, 0});
    }

    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            ls.apply(l - 1, r, true);
        }
        else
        {
            cout << ls.prod(l - 1, r).inv << "\n";
        }
    }
    return 0;
}
