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
    int h, w;
    cin >> h >> w;
    vs mp(h);

    int minx = 10000, maxx = -1, miny = 10000, maxy = -1;
    for (int i = 0; i < h; i++)
    {
        cin >> mp[i];
        for (int j = 0; j < w; j++)
        {
            if (mp[i][j] == '#')
            {
                minx = min(i, minx);
                maxx = max(i, maxx);
                miny = min(j, miny);
                maxy = max(j, maxy);
            }
        }
    }

    for (int i = minx; i <= maxx; i++)
    {
        for (int j = miny; j <= maxy; j++)
        {
            if (mp[i][j] == '.')
            {
                no();
                return 0;
            }
        }
    }
    yes();
    return 0;
}
