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

const int N = 200005;
int l[N], cnt[10];
mint998 fac[N], finv[N], sm[10];
vc<mint998> fm1[10], fi[10];

vc<mint998> pow_poly(vc<mint998> &p, int q)
{
    vc<mint998> ret(1, 1), ps(p);
    while (q)
    {
        if (q % 2 == 1)
            ret = convolution<mint998>(ret, ps);

        q >>= 1;
        ps = convolution<mint998>(ps, ps);
    }
    return ret;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    l[0] = 1;
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        l[i] = l[i / 10] * 10;
        fac[i] = fac[i - 1] * i;
        cnt[to_string(i).length()]++;
        sm[to_string(i).length()] += i;
    }
    cout << "\n";

    mint998 ten = 10;
    for (int i = 1; cnt[i] > 0; i++)
    {
        fi[i].push_back(1);
        fi[i].push_back(ten);
        ten *= 10;
    }

    mint998 ans = 0;
    for (int i = 1; cnt[i] > 0; i++)
    {
        fm1[i].resize(1, 1);
        for (int j = 1; cnt[j] > 0; j++)
        {
            int cnt_now = i == j ? cnt[j] - 1 : cnt[j];
            fm1[i] = convolution<mint998>(fm1[i], pow_poly(fi[j], cnt_now));
        }
        for (int j = 0; j < n; j++)
        {
            ans += fm1[i][j] * sm[i] * fac[j] * fac[n - 1 - j];
        }
    }

    cout << ans.val();

    return 0;
}
