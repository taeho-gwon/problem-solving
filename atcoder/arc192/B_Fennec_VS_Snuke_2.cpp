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

void f() { cout << "Fennec"; }
void s() { cout << "Snuke"; }
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    vi a(n);
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 1)
            odd++;
    }
    if (n == 1)
        f();
    else if (n == 2)
        s();
    else if (odd == 0)
        s();
    else if (n == 3)
        f();
    else if (odd % 2 == 1)
        f();
    else
        s();
}
