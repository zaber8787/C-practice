#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define mem(x, y) memset((x), (y), sizeof(x))
#define loli ios::sync_with_stdio(0), cin.tie(0)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template <typename Ta, typename Tb>
istream &operator>>(istream &in, pair<Ta, Tb> &p) { return in >> p.first >> p.second; }
template <typename Ta, typename Tb>
ostream &operator<<(ostream &out, pair<Ta, Tb> &p) { return out << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
void arr_print(T a, T b)
{
    T i = a;
    for (cout << *i++; i != b; i++)
        cout << " " << *i;
    cout << "\n";
}
ostream &print() { return cout << "\n"; }
template <typename T>
ostream &print(T a) { return cout << a << "\n"; }
template <typename T, typename... Args>
ostream &print(T a, Args... args)
{
    cout << a << " ";
    return print(args...);
}

//--------------------Main Code--------------------
vector<vector<int>> v;
vector<int> ans;
vector<bool> vis;
bool impossible = false;

void add_relation(int a, int b)
{
    v[a].pb(b);
    v[b].pb(a);
    return;
}

int assign_team(int a)
{
    if (a == 1)
        return 2;
    else
        return 1;
}

void dfs(int a)
{
    if (vis[a])
        return;

    vis[a] = 1;
    if (impossible)
        return;

    if (!ans[a])
        ans[a] = 1;

    for (int i : v[a])
    {

        if (!ans[i])
        {
            ans[i] = assign_team(ans[a]);
            dfs(i);
        }
        else if (ans[i] != assign_team(ans[a]))
        {
            impossible = 1;
            return;
        }
    }
}

int main()
{

    queue<pii> q;
    int n, m;
    cin >> n >> m;
    v.resize(n);
    ans.resize(n, 0);
    vis.resize(n, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        add_relation(a, b);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i);
    }

    if (impossible)
        print("IMPOSSIBLE");
    else
    {
        for (auto i : ans)
            cout << i << " ";
    }
}