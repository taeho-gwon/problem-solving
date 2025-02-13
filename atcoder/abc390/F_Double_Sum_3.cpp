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

int n;
ll f(vi &a)
{
    a.push_back(n + 1);
    ll ret = (ll)a[0] * (a[0] - 1) / 2;

    for (int i = 1; i < a.size(); i++)
    {
        ll dif = a[i] - a[i - 1];
        ret += dif * (dif - 1) / 2;
    }
    a.pop_back();
    return ret;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cin >> n;

    vvi a(n + 2);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x].push_back(i);
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        vi tmp(a[i].size() + a[i + 1].size());
        std::merge(a[i].begin(), a[i].end(), a[i + 1].begin(), a[i + 1].end(), tmp.begin());
        ans += f(a[i + 1]);
        ans -= f(tmp);
    }
    cout << ans;
    return 0;
}
