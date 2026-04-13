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

void f(map<int, int> &mp, vector<queue<int>> &v, int a, int b, bool re)
{
    queue<int> temp;
    int from = mp[a], tar = mp[b];
    if (from == tar)
        return;

    while (v[from].front() != a)
    {
        temp.push(v[from].front());
        v[from].pop();
    }

    mp[v[from].front()] = tar;
    v[tar].push(v[from].front());
    v[from].pop();

    while (!v[from].empty())
    {
        if (re)
        {
            mp[v[from].front()] = v[from].front();
            v[v[from].front()].push(v[from].front());
        }
        else
        {
            mp[v[from].front()] = tar;
            v[tar].push(v[from].front());
        }
        v[from].pop();
    }

    while (!temp.empty())
    {
        v[from].push(temp.front());
        temp.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<queue<int>> v(n);
    map<int, int> mp;
    string s;
    for (int i = 0; i < n; i++)
    {
        mp[i] = i;
        v[i].push(i);
    }
    while (getline(cin, s) && s != "quit")
    {
        stringstream ss(s);
        string M, W, c, d;
        int a, b;

        ss >> M >> c >> W >> d;
        a = stoi(c);
        b = stoi(d);

        if (M == "move" && W == "onto" && mp[a] != mp[b])
        {
            f(mp, v, a, b, true);
            // v[a].pop();
            // v[b].push(a);
            // mp[a] = b;
        }
        if (M == "move" && W == "over" && mp[a] != mp[b])
        {
            f(mp, v, a, b, true);
            // v[a].pop();
            // v[mp[b]].push(a);
            // mp[a] = mp[b];
        }
        if (M == "pile" && mp[a] != mp[b])
        {
            f(mp, v, a, b, false);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        while (!v[i].empty())
        {
            cout << " " << v[i].front();
            v[i].pop();
        }
        print();
    }
}