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
// https://zerojudge.tw/ShowProblem?problemid=c012

int main()
{
    loli;
    string s;
    bool first = true;
    while (getline(cin, s))
    {
        if (!first)
            cout << "\n";
        first = false;
        vector<pair<char, int>> v(128);
        for (int i = 0; i < 128; i++)
            v[i] = {char(i), 0};

        for (char c : s)
        {
            v[c].S++;
        }

        sort(v.begin(), v.end(), [](const pair<char, int> &a, const pair<char, int> &b)
             {
        if (a.S != b.S)
            return a.S < b.S;
        return a.F > b.F; });

        for (int i = 0; i < 128; i++)
            if (v[i].S)
                cout << int(v[i].F) << " " << v[i].S << "\n";
    }
}