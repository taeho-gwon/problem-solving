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

const int N = 1234567;
int n, k, cnt[N], cnt2[N];
int a[N], ans[N];

int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    int n, k;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt2[a[i]]++;
    }

    cnt[1] = n;
    for (int i = 2; i <= 1000000; i++)
    {
        for (int j = i; j <= 1000000; j += i)
        {
            cnt[i] += cnt2[j];
        }
    }

    for (int i = 1; i <= 1000000; i++)
    {
        if (cnt[i] < k)
            continue;
        for (int j = i; j <= 1000000; j += i)
        {
            ans[j] = max(ans[j], i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[a[i]] << "\n";
    }
    return 0;
}
