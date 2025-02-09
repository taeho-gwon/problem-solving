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
    int n, q;
    cin >> n >> q;

    vi a(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        cnt[i] = 1;
    }

    int ans = 0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int p, h;
            cin >> p >> h;
            cnt[a[p]]--;
            if (cnt[a[p]] == 1)
                ans--;
            a[p] = h;

            if (cnt[a[p]] == 1)
                ans++;
            cnt[a[p]]++;
        }
        else
        {
            cout << ans << "\n";
        }
    }
    return 0;
}
