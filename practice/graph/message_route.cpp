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
queue<int> q;
vector<bool> vis;
vector<int> dis;
vector<int> from;

void add_route(int a, int b)
{
    v[a].pb(b);
    v[b].pb(a);
    return;
}

void bfs()
{
    if (q.empty())
        return;
    int ptr = q.front();
    q.pop();
    for (int i : v[ptr])
    {
        if (vis[i])
            continue;
        dis[i] = dis[ptr] + 1;
        from[i] = ptr;
        vis[i] = 1;
        if (i == vis.size() - 1)
            return;
        q.push(i);
    }
    bfs();
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    v.resize(n);
    vis.resize(n, 0);
    from.resize(n, -1);
    dis.resize(n, 1145141);
    dis[0] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        add_route(a, b);
    }

    q.push(0);
    bfs();

    if (from.back() == -1)
        print("IMPOSSIBLE");
    else
    {
        int ptr = n - 1;
        stack<int> path;
        while (true)
        {
            if (!from[ptr])
                break;
            path.push(from[ptr]);
            ptr = from[ptr];
        }
        print(path.size() + 2);
        cout << "1 ";
        while (!path.empty())
        {
            cout << path.top() + 1 << " ";
            path.pop();
        }
        cout << n;
    }
}