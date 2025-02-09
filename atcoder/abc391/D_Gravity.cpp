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
    int n, w;
    cin >> n >> w;

    const int INF = 1 << 30;
    vvpi a(w + 1);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back({y, i});
    }
    vi c(n + 2), d(n + 2, -1);
    for (int i = 1; i <= w; i++)
    {
        sort(a[i].begin(), a[i].end());

        for (int j = 0; j < a[i].size(); j++)
        {
            c[a[i][j].second] = j;
            d[j] = max(d[j], a[i][j].first);
        }
        d[a[i].size()] = INF;
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] = max(d[i - 1] + 1, d[i]);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int t, x;
        cin >> t >> x;
        yesno(d[c[x]] > t);
    }
    return 0;
}
