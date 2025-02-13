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

int n;
ll a[15];
vl group;
unordered_set<ll> ans;

void dfs(int idx)
{
    if (idx == n)
    {
        ll ret = 0;
        for (ll num : group)
        {
            ret ^= num;
        }
        ans.insert(ret);
        return;
    }
    for (int i = 0; i < group.size(); i++)
    {
        group[i] += a[idx];
        dfs(idx + 1);
        group[i] -= a[idx];
    }
    group.push_back(a[idx]);
    dfs(idx + 1);
    group.pop_back();
}
int main()
{
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dfs(0);
    cout << ans.size();

    return 0;
}
