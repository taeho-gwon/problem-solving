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

    ll r, quat = 0;
    cin >> r;
    for (ll i = 1; i < r; i++)
    {
        ll vl = 0, vr = r;
        while (vl + 1 < vr)
        {
            ll mid = (vl + vr) / 2;
            if ((2 * i + 1) * (2 * i + 1) + (2 * mid + 1) * (2 * mid + 1) <= 4 * r * r)
                vl = mid;
            else
                vr = mid;
        }
        quat += vl;
    }
    cout << quat * 4 + 4 * r - 3;
    return 0;
}
