#include <bits/stdc++.h>

using namespace std;

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

int f(int x)
{
    if (x < 0)
        return 987654321;
    int ans = 1;
    ans += x / 600;
    x %= 600;
    ans += x / 60;
    x %= 60;
    ans += x / 10;
    return ans;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    str ss;
    cin >> ss;

    int m = (ss[0] - '0') * 10 + ss[1] - '0';
    int s = (ss[3] - '0') * 10 + ss[4] - '0';
    s += m * 60;
    cout << min(f(s), f(s - 30));
    return 0;
}
