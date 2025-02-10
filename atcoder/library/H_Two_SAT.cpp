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

    int n, d;
    cin >> n >> d;
    vi x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    two_sat g(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(x[i] - x[j]) < d)
                g.add_clause(i, true, j, true);
            if (abs(x[i] - y[j]) < d)
                g.add_clause(i, true, j, false);
            if (abs(y[i] - x[j]) < d)
                g.add_clause(i, false, j, true);
            if (abs(y[i] - y[j]) < d)
                g.add_clause(i, false, j, false);
        }
    }
    if (g.satisfiable())
    {
        yes();
        vc<bool> ans = g.answer();
        for (int i = 0; i < n; i++)
        {
            if (ans[i])
                cout << y[i];
            else
                cout << x[i];
            cout << "\n";
        }
    }
    else
        no();
    return 0;
}
