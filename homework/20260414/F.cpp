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

pair<bool, pair<set<int>, int>> f(vector<vector<int>> v, set<int> s, int n)
{
    if (v[n].size() < 2)
    {
        return make_pair(false, make_pair(s, n));
    }
    for (int i : v[n])
    {
        if (i == n)
            continue;
        if (s.find(i) != s.end())
        {
            return make_pair(true, make_pair(s, i));
        }
        s.insert(i);
        pair<bool, pair<set<int>, int>> p = f(v, s, i);
        if (p.F == false)
            continue;
    }
    return make_pair(false, make_pair(s, n));
}

bool check(set<int> st, vector<vector<int>> v, int a, int goal)
{
    for (int j : v[a])
    {
        if (st.find(j) != st.end()){
            
        }
    }
    return
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    bool possible = false;
    for (int i = 1; i <= m; i++)
    {
        set<int> s;
        queue<int> q;
        pair<bool, pair<set<int>, int>> p = f(v, s, i);
        if (p.F == false)
            continue;
        else
        {
            possible = true;
            set<int> s = p.S.F;

            int a = p.S.S, goal = a;
            while (true)
            {
                for (int j : v[a])
                {
                    if ()
                }
            }
        }
    }
}