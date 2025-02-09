#include <bits/stdc++.h>
#include <atcoder/all>

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
    vpi e(m + 1);
    dsu d(n + 1);
    vi remain;
    for (int i = 1; i <= m; i++)
    {
        cin >> e[i].first >> e[i].second;
        if (d.same(e[i].first, e[i].second))
        {
            remain.push_back(i);
        }
        else
        {
            d.merge(e[i].first, e[i].second);
        }
    }

    int ans = d.groups().size() - 2;
    cout << ans << "\n";

    int now = 1;
    for (int e_idx : remain)
    {
        if (ans == 0)
            break;
        int u = e[e_idx].first;
        while (d.same(now, u))
        {
            now++;
            if (now == n + 1)
                now = 1;
        }
        d.merge(now, u);
        ans--;
        cout << e_idx << " " << u << " " << now << "\n";
    }

    return 0;
}
