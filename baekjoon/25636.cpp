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

const int N = 101010;
const ll INF = 1LL << 60;
ll a[N];
ll dist[N], water[N];
int n, m, s, e;
vpl adj[N];

struct pqdata
{
    ll cost, water, node;
};
struct compare
{
    bool operator()(pqdata &o1, pqdata &o2)
    {
        if (o1.cost == o2.cost)
            return o1.water < o2.water;
        return o1.cost > o2.cost;
    }
};
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dist[i] = INF;
        water[i] = 0;
    }

    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cin >> s >> e;

    dist[s] = 0;
    water[s] = a[s];

    priority_queue<pqdata, vc<pqdata>, compare> q;
    q.push({0, a[s], s});

    while (!q.empty())
    {
        auto [c, w, f] = q.top();
        q.pop();
        if (dist[f] < c)
            continue;

        for (auto [nxt, nd] : adj[f])
        {
            ll newc = nd + c, neww = w + a[nxt];
            if (dist[nxt] > newc || (dist[nxt] == newc && water[nxt] < neww))
            {
                dist[nxt] = newc;
                water[nxt] = neww;
                q.push({dist[nxt], water[nxt], nxt});
            }
        }
    }
    if (dist[e] == INF)
        cout << "-1";
    else
        cout << dist[e] << " " << water[e];
    return 0;
}
