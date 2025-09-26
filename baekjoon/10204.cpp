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

int getint()
{
    str s;
    cin >> s;
    int num = 0;
    for (int i = 1; i < s.length(); i++)
    {
        num *= 10;
        num += s[i] - '0';
    }
    return num;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vvi adj(n + 1, vi());
    for (int i = 0; i < m; i++)
    {
        int s = getint();
        int e = getint();
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    int s = getint();
    queue<int> q;
    vi visit(n + 1);
    q.push(s);
    visit[s] = 1;
    for (int i = 0; i < 2; i++)
    {
        int qsz = q.size();

        for (int j = 0; j < qsz; j++)
        {
            int f = q.front();
            q.pop();
            for (int nxt : adj[f])
            {
                if (visit[nxt] == 1)
                    continue;
                q.push(nxt);
                visit[nxt] = 1;
            }
        }
    }
    int ans = accumulate(visit.begin(), visit.end(), -1);
    cout << "The number of supervillains in 2-hop neighborhood of v" << s << " is " << ans << "\n";
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int z;
    cin >> z;
    while (z--)
    {
        solve();
    }
    return 0;
}
