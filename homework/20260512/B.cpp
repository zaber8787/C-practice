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

void bfs(int n)
{
    int color = v[n];
    for (int i : gr[n])
    {
        if (v[i] == -1)
        {
            q.push(i);
            if (color == 1)
                v[i] = 2;
            else
                v[i] = 1;
        }
        if(color == v[i])
    }
}

queue<int> q;
//--------------------Main Code--------------------
vector<int> v;
vector<vector<int>> gr;
int main()
{
    loli;
    int n, l;
    while (cin >> n)
    {
        if (!n)
            break;
        v.resize(n, -1);
        v[0] = 1;
        gr.resize(n);
        cin >> l;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
    }
}