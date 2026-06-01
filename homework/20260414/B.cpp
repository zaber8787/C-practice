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

int n;
vector<vector<int>> v; 
vector<int> pos;     

void clear_above(int x)
{
    int p = pos[x];
    while (v[p].back() != x)
    {
        int top = v[p].back();
        v[top].push_back(top); 
        pos[top] = top;        
        v[p].pop_back();       
    }
}


void pile_to(int a, int b)
{
    int pa = pos[a];
    int pb = pos[b];
    vector<int> temp;

    auto it = find(v[pa].begin(), v[pa].end(), a);
    for (auto i = it; i != v[pa].end(); ++i)
    {
        temp.push_back(*i);
        pos[*i] = pb; 
    }

    v[pa].erase(it, v[pa].end());

    for (int x : temp)
    {
        v[pb].push_back(x);
    }
}

int main()
{
    loli;

    if (!(cin >> n))
        return 0;

    v.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; i++)
    {
        v[i].push_back(i);
        pos[i] = i;
    }

    string s1, s2;
    int a, b;
    while (cin >> s1 && s1 != "quit")
    {
        cin >> a >> s2 >> b;

        if (a == b || pos[a] == pos[b])
            continue;

        if (s1 == "move")
            clear_above(a);
        if (s2 == "onto")
            clear_above(b);

        pile_to(a, b);
    }


    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        for (int x : v[i])
        {
            cout << " " << x;
        }
        cout << "\n";
    }

    return 0;
}