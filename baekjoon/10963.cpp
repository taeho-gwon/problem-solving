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

const int N = 25;
int n, m;
int adj[N][N];
int color[N];

bool is_ok(int node, int col)
{
    for (int i = 1; i < node; i++)
    {
        if (adj[i][node] && color[i] == col)
            return false;
    }
    return true;
}
bool can_color_k(int node, int col, int k)
{
    if (!is_ok(node, col))
        return false;
    color[node] = col;
    if (node == n)
        return true;

    for (int i = 1; i <= k; i++)
    {
        if (can_color_k(node + 1, i, k))
            return true;
    }
    return false;
}

int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        adj[s][e] = adj[e][s] = 1;
    }

    for (int i = 1; i < N; i++)
    {
        if (can_color_k(1, 1, i))
        {
            cout << i << "\n";
            vvi ans(i + 1);
            for (int j = 1; j <= n; j++)
                ans[color[j]].push_back(j);
            for (int j = 1; j <= i; j++)
            {
                for (int k : ans[j])
                    cout << k << " ";
                cout << "\n";
            }

            return 0;
        }
    }
    return 0;
}
