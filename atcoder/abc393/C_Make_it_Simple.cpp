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

int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    set<pi> s;
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        if (u == v)
            ans++;
        else if (s.count({u, v}) == 0)
        {
            s.insert({u, v});
        }

        else
            ans++;
    }
    cout << ans;
    return 0;
}
