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

int op(int x, int y)
{
    return max(x, y);
}
int e()
{
    return -1;
}

int target;
bool f(int k)
{
    return k < target;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    segtree<int, op, e> st(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        st.set(i, a);
    }
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, v;
            cin >> x >> v;
            st.set(x - 1, v);
        }
        else if (t == 2)
        {
            int l, r;
            cin >> l >> r;
            cout << st.prod(l - 1, r) << "\n";
        }
        else
        {
            int x, v;
            cin >> x >> v;
            target = v;
            cout << st.max_right<f>(x - 1) + 1 << "\n";
        }
    }
    return 0;
}
