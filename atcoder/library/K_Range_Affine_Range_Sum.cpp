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
    mint998 val;
    int sz;
};
S op(S p, S q)
{
    return S{p.val + q.val, p.sz + q.sz};
}
S e()
{
    return S{0, 0};
}

struct F
{
    mint998 b, c;
};
S mapping(F f, S p)
{
    return S{p.val * f.b + p.sz * f.c, p.sz};
}
F composition(F f, F g)
{
    return F{f.b * g.b, f.b * g.c + f.c};
}
F id()
{
    return F{1, 0};
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    lazy_segtree<S, op, e, F, mapping, composition, id> ls(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ls.set(i, {x, 1});
    }

    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 0)
        {
            int b, c;
            cin >> b >> c;
            ls.apply(l, r, F{b, c});
        }
        else
        {
            cout << ls.prod(l, r).val.val() << "\n";
        }
    }
    return 0;
}
