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
    int n;
    ll m;
    cin >> n >> m;
    vl p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    ll l = 0, r = m + 1;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        ll cost = 0;
        bool chk = true;
        for (int i = 0; i < n; i++)
        {
            ll nowcnt = (p[i] + mid) / (2 * p[i]);
            if (nowcnt == 0)
                continue;
            if ((m - cost) / nowcnt < nowcnt * p[i])
            {
                cost = m + 1;
                break;
            }
            ll nowcost = nowcnt * nowcnt * p[i];
            cost += nowcost;
        }
        if (cost <= m)
            l = mid;
        else
            r = mid;
    }

    ll ans = 0, tmp = 0, cost = 0;
    for (int i = 0; i < n; i++)
    {
        ll nowcnt = (p[i] + l) / (2 * p[i]);
        ans += (p[i] + l) / (2 * p[i]);
        cost += nowcnt * nowcnt * p[i];
        if ((2 * nowcnt + 1) * p[i] == l + 1)
            tmp++;
    }
    cout << ans + min((m - cost) / (l + 1), tmp);
    return 0;
}
