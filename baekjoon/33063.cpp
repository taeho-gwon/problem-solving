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

const int N = 1005;
int xy[N][N], yz[N][N], zx[N][N];
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int ans = 0;
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        xy[x][y]++;
        yz[y][z]++;
        zx[z][x]++;
        if (xy[x][y] == n)
            ans++;
        if (yz[y][z] == n)
            ans++;
        if (zx[z][x] == n)
            ans++;
        cout << ans << "\n";
    }
    return 0;
}