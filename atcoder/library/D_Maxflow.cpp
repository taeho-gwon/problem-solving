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
    vs mp(n);
    for (int i = 0; i < n; i++)
        cin >> mp[i];

    mf_graph<int> mf(n * m + 2);
    int source = n * m, sink = n * m + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == '#')
                continue;
            int node_num = i * m + j;
            if ((i + j) % 2 == 0)
            {
                mf.add_edge(source, node_num, 1);
                int d[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
                for (int k = 0; k < 4; k++)
                {
                    int ni = i + d[k][0], nj = j + d[k][1];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && mp[ni][nj] == '.')
                    {
                        mf.add_edge(node_num, ni * m + nj, 1);
                    }
                }
            }
            else
            {
                mf.add_edge(node_num, sink, 1);
            }
        }
    }

    cout << mf.flow(source, sink) << "\n";

    for (auto e : mf.edges())
    {
        if (e.from == source || e.to == sink || e.flow == 0)
            continue;

        if (e.from + m == e.to)
        {
            mp[e.from / m][e.from % m] = 'v';
            mp[e.to / m][e.to % m] = '^';
        }
        else if (e.from - m == e.to)
        {
            mp[e.from / m][e.from % m] = '^';
            mp[e.to / m][e.to % m] = 'v';
        }
        else if (e.from + 1 == e.to)
        {
            mp[e.from / m][e.from % m] = '>';
            mp[e.to / m][e.to % m] = '<';
        }
        else
        {
            mp[e.from / m][e.from % m] = '<';
            mp[e.to / m][e.to % m] = '>';
        }
    }
    for (int i = 0; i < n; i++)
        cout << mp[i] << "\n";
}
