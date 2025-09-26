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

const int INF = 987654321;
struct Puzzle
{
    int h, w;
    vs d;
} p1, p2;

Puzzle get_puzzle()
{
    Puzzle p;
    cin >> p.h >> p.w;
    p.d.resize(p.h);
    for (int i = 0; i < p.h; i++)
        cin >> p.d[i];

    return p;
}

int g(int x, int y)
{
    int a[200][200] = {
        0,
    };

    int minh = INF, maxh = -1, minw = INF, maxw = -1;
    for (int i = 0; i < p1.h; i++)
    {
        for (int j = 0; j < p1.w; j++)
        {
            int nowh = p2.h + i;
            int noww = p2.w + j;
            a[nowh][noww] = p1.d[i][j] - '0';
            if (p1.d[i][j] == '1')
            {
                minh = min(minh, nowh);
                maxh = max(maxh, nowh);
                minw = min(minw, noww);
                maxw = max(maxw, noww);
            }
        }
    }

    for (int i = 0; i < p2.h; i++)
    {
        for (int j = 0; j < p2.w; j++)
        {
            int nowh = p2.h + i + x;
            int noww = p2.w + j + y;
            a[nowh][noww] += p2.d[i][j] - '0';
            if (a[nowh][noww] == 2)
                return INF;

            if (p2.d[i][j] == '1')
            {
                minh = min(minh, nowh);
                maxh = max(maxh, nowh);
                minw = min(minw, noww);
                maxw = max(maxw, noww);
            }
        }
    }
    return (maxh - minh + 1) * (maxw - minw + 1);
}
int f()
{
    int ans = 10000;

    for (int i = -p2.h; i < p1.h; i++)
    {
        for (int j = -p2.w; j < p1.w; j++)
        {
            ans = min(ans, g(i, j));
        }
    }
    return ans;
}

Puzzle rotate(Puzzle x)
{
    Puzzle ret;
    ret.h = x.w;
    ret.w = x.h;
    for (int i = 0; i < ret.h; i++)
    {
        string now = "";
        for (int j = 0; j < ret.w; j++)
        {
            now.push_back(x.d[j][ret.h - 1 - i]);
        }
        ret.d.push_back(now);
    }
    return ret;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    p1 = get_puzzle(), p2 = get_puzzle();

    int ans = 10000;
    for (int i = 0; i < 4; i++)
    {
        ans = min(f(), ans);
        p2 = rotate(p2);
    }
    cout << ans;
    return 0;
}
