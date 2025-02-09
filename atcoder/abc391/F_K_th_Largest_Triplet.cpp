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
ll a[200005], b[200005], c[200005];
ll calc(int ai, int bi, int ci)
{
    return a[ai] * b[bi] + b[bi] * c[ci] + c[ci] * a[ai];
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    pq<tuple<ll, int, int, int>> q;
    set<tuple<int, int, int>> s;
    q.push({calc(n - 1, n - 1, n - 1), n - 1, n - 1, n - 1});
    s.insert({n - 1, n - 1, n - 1});
    while (--m)
    {
        auto [_, i, j, k] = q.top();
        q.pop();

        if (i > 0 && s.count({i - 1, j, k}) == 0)
        {
            q.push({calc(i - 1, j, k), i - 1, j, k});
            s.insert({i - 1, j, k});
        }
        if (j > 0 && s.count({i, j - 1, k}) == 0)
        {
            q.push({calc(i, j - 1, k), i, j - 1, k});
            s.insert({i, j - 1, k});
        }
        if (k > 0 && s.count({i, j, k - 1}) == 0)
        {
            q.push({calc(i, j, k - 1), i, j, k - 1});
            s.insert({i, j, k - 1});
        }
    }
    cout << get<0>(q.top());
    return 0;
}
