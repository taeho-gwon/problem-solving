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

ll get(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    ll x;
    cin >> x;
    return x;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    vl p(n + 1), a(n + 1);
    vl v_1i(n + 1), v_2i(n + 1);
    ll v_12 = get(1, 2);
    ll a1, a2;
    for (int i = 3; i <= n; i++)
    {
        v_1i[i] = get(1, i);
        v_2i[i] = get(2, i);
    }

    vc<tuple<ll, ll, int>> x(n + 1);
    x[1] = {0, -v_12, 1};
    x[2] = {v_12, 0, 2};
    for (int i = 3; i <= n; i++)
    {
        if (v_12 > v_1i[i] && v_12 > v_2i[i])
            x[i] = {v_1i[i], -v_2i[i], i};
        else if (v_2i[i] > v_12 && v_2i[i] > v_1i[i])
            x[i] = {-v_1i[i], -v_2i[i], i};
        else
            x[i] = {v_1i[i], v_2i[i], i};
    }
    sort(x.begin() + 1, x.end());
    for (int i = 1; i <= n; i++)
    {
        p[get<2>(x[i])] = i;
    }

    int idx1, idx2;
    for (int i = 1; i + 1 < p[2]; i++)
    {
        a[i] = get<1>(x[i + 1]) - get<1>(x[i]);
    }
    for (int i = p[1] + 2; i <= n; i++)
    {
        a[i] = get<0>(x[i]) - get<0>(x[i - 1]);
    }
    if (p[1] + 1 == p[2])
    {
        if (p[1] > 1)
        {
            a[p[2]] = get<0>(x[1]) - get<1>(x[1]);
            a[p[1]] = v_12 - a[p[2]];
        }
        else
        {
            a[p[1]] = get<0>(x[n]) - get<1>(x[n]);
            a[p[2]] = v_12 - a[p[1]];
        }
    }
    else if (p[1] + 2 == p[2])
    {
        int mid = p[1] + 1;
        a[mid] = get<0>(x[mid]) - get<1>(x[mid]) - v_12;
    }
    cout << "!";
    for (int i = 1; i <= n; i++)
        cout << " " << p[i];
    for (int i = 1; i <= n; i++)
        cout << " " << a[i];
    cout << endl;
}