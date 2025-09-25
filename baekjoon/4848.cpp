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

string num[16];
int f(str s)
{
    for (int i = 0; i < 16; i++)
    {
        if (s == num[i])
            return i;
    }
    return -1;
}

int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    num[0] = "{}";
    for (int i = 1; i < 16; i++)
    {
        num[i] = "{" + num[0];

        for (int j = 1; j < i; j++)
        {
            num[i] += "," + num[j];
        }
        num[i] += "}";
    }
    int n;
    cin >> n;
    while (n--)
    {
        str s1, s2;
        cin >> s1 >> s2;
        cout << num[f(s1) + f(s2)] << "\n";
    }
    return 0;
}
