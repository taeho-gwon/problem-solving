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

int count_hole(char c)
{
    string hole1 = "AabDdegOoPpQqR@";
    if (c == 'B')
        return 2;
    return (int)(hole1.find(c) != string::npos);
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    str s;
    getline(cin, s);

    cout << accumulate(s.begin(), s.end(), 0, [](int sum, char c)
                       { return sum + count_hole(c); });
    return 0;
}
