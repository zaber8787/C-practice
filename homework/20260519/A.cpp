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

void dfs(vector<bool> &vis, vector<vector<int>> &v, int n)
{
    for (int i : v[n])
    {
        if (vis[i])
            continue;
        vis[i] = true;
        dfs(vis, v, i);
    }
}

int main()
{
    loli;
    int n;
    while (cin >> n)
    {
        if (!n)
            break;
        vector<vector<int>> v(n + 1);
        int m, l;
        while (cin >> m)
        {
            if (!m)
                break;
            while (cin >> l)
            {
                if (!l)
                    break;
                v[m].pb(l);
            }
        }
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> l;
            vector<bool> vis(n + 1, false);
            dfs(vis, v, l);
            set<int> st;
            for (int j = 1; j <= n; j++)
            {
                if (!vis[j])
                    st.insert(j);
            }
            cout << st.size();
            for (auto t : st)
                cout << " " << t;
            cout << "\n";
        }
    }
}