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

    int n;
    cin >> n;
    vi k(n);
    vc<map<int, int>> dice(n);

    long double ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++)
        {
            int x;
            cin >> x;
            if (dice[i].count(x) == 0)
                dice[i][x] = 0;
            dice[i][x]++;
        }

        for (int j = 0; j < i; j++)
        {
            ll cnt = 0;
            for (auto [k, v] : dice[i])
            {
                if (dice[j].count(k) == 0)
                    continue;
                cnt += (ll)v * dice[j][k];
            }
            long double now = (long double)cnt / k[i] / k[j];
            ans = max(ans, now);
        }
    }
    cout.precision(15);
    cout << ans;
    return 0;
}
