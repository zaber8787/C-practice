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
vector<bool> connected;
vector<pii> ans;

void add_road(int a, int b)
{
    v[a].pb(b);
    v[b].pb(a);
    return;
}

void dfs(int p)
{
    for (int i : v[p])
    {
        if (connected[i])
            continue;
        else
        {
            connected[i] = 1;
            dfs(i);
        }
    }
}

int main()
{
    loli;
    int n, m, a, b;
    cin >> n >> m;
    v.resize(n);
    connected.resize(n, 0);
    connected[0] = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        add_road(a, b);
    }

    dfs(0);
    for (int i = 1; i < n; i++)
    {
        if (!connected[i])
        {
            add_road(0, i);
            ans.pb(make_pair(0, i));
            connected[i] = 1;
            dfs(i);
        }
    }

    print(ans.size());
    for (pii i : ans)
        print(i.F + 1, i.S + 1);
}