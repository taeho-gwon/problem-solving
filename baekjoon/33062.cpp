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

int l[8], r[8];
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int z;
    cin >> z;
    l[0] = 45;
    r[0] = 50;
    for (int i = 1; i < 8; i++)
    {
        l[i] = l[i - 1] * 10 - 5;
        r[i] = r[i - 1] * 10;
    }
    while (z--)
    {
        int n, ans = 0;
        cin >> n;

        for (int i = 0; i < 8 && n >= l[i]; i++)
        {
            if (n < r[i])
                ans += n - l[i] + 1;

            else
                ans += r[i] - l[i];
        }
        cout << ans << "\n";
    }
    return 0;
}