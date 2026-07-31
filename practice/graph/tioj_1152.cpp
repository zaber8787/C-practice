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
vector<bool> vis;
vector<int> level;

void dfs(int n)
{
    for (int i : v[n])
    {
        if (vis[i])
            continue;
        level[i] = max(level[i], level[n] + 1);
        vis[i] = 1;
        dfs(i);
    }
}

int main()
{
    int n, tmp;
    cin >> n;
    v.resize(n);
    vis.resize(n, 0);
    level.resize(n, 0);
    for (int i = 0; i < n; i++)
        while (cin >> tmp && tmp != -1)
        {
            v[i].pb(tmp);
            v[tmp].pb(i);
        }

    dfs(0);
    int Max = 0, ptr = 0;
    for (int i = 0; i < n; i++)
    {
        if (level[i] > Max)
        {
            Max = level[i];
            ptr = i;
        }
    }
    vis.resize(n, 0);
    dfs(ptr);

    int ans = 0;
    for (auto i : level)
        ans = max(ans, i);
    print(ans);
}