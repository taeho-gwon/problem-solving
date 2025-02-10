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
    int n, k;
    cin >> n >> k;
    vvi a(n);
    mcf_graph<int, ll> mcf(n * 2 + 2);
    int source = 2 * n, sink = 2 * n + 1;

    const ll INF = 1LL << 30;
    for (int i = 0; i < n; i++)
    {
        a[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> a[i][j];
            mcf.add_edge(i, j + n, 1, INF - a[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        mcf.add_edge(source, i, k, 0);
        mcf.add_edge(n + i, sink, k, 0);
    }
    mcf.add_edge(source, sink, n * k, INF);
    cout << n * k * INF - mcf.flow(source, sink, n * k).second << "\n";

    vvi check(n);
    for (int i = 0; i < n; i++)
        check[i].resize(n);
    for (auto e : mcf.edges())
    {
        if (e.from == source || e.to == sink || e.flow == 0)
            continue;
        check[e.from][e.to - n] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check[i][j])
                cout << "X";
            else
                cout << ".";
        }
        cout << "\n";
    }
    return 0;
}
