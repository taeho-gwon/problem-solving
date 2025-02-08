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

str q(char p, char q)
{
    cout << "? " << p << " " << q << endl;
    str ret;
    cin >> ret;
    return ret;
}
void answer5(char p1, char p2, char p3, char p4, char p5)
{
    cout << "! " << p1 << p2 << p3 << p4 << p5 << endl;
}
void sort5()
{
    str a = "ABCDE";
    if (q(a[0], a[1]) == ">")
        swap(a[0], a[1]);
    if (q(a[2], a[3]) == ">")
        swap(a[2], a[3]);
    if (q(a[0], a[2]) == ">")
    {
        swap(a[0], a[2]);
        swap(a[1], a[3]);
    }
    if (q(a[2], a[4]) == "<")
    {
        if (q(a[3], a[4]) == ">")
            swap(a[3], a[4]);

        if (q(a[1], a[3]) == "<")
        {
            if (q(a[1], a[2]) == ">")
                swap(a[1], a[2]);
            answer5(a[0], a[1], a[2], a[3], a[4]);
        }
        else
        {
            if (q(a[1], a[4]) == ">")
                swap(a[1], a[4]);
            answer5(a[0], a[2], a[3], a[1], a[4]);
        }
    }
    else
    {
        if (q(a[1], a[2]) == "<")
        {
            if (q(a[0], a[4]) == "<")
            {
                if (q(a[1], a[4]) == ">")
                    swap(a[1], a[4]);
                answer5(a[0], a[1], a[4], a[2], a[3]);
            }
            else
                answer5(a[4], a[0], a[1], a[2], a[3]);
        }
        else
        {
            if (q(a[0], a[4]) == ">")
                swap(a[0], a[4]);
            if (q(a[1], a[3]) == ">")
                swap(a[1], a[3]);
            answer5(a[0], a[4], a[2], a[1], a[3]);
        }
    }
}

str msort(str a)
{
    int l = a.length();
    if (l == 1)
        return a;
    str a1 = msort(a.substr(0, l / 2));
    str a2 = msort(a.substr(l / 2));

    int l1 = a1.length(), l2 = a2.length(), i = 0, j = 0;
    str ret = "";
    while (i < l1 || j < l2)
    {
        if (i == l1)
            ret.push_back(a2[j++]);
        else if (j == l2)
            ret.push_back(a1[i++]);
        else if (q(a1[i], a2[j]) == ">")
            ret.push_back(a2[j++]);
        else
            ret.push_back(a1[i++]);
    }
    return ret;
}
void sort26()
{
    string a = "QWERTYUIOPASDFGHJKLZXCVBNM";
    a = msort(a);
    cout << "! " << a << endl;
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    if (n == 5)
        sort5();
    else
        sort26();
    return 0;
}
