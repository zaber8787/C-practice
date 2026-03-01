#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define mem(x, y) memset((x), (y), sizeof(x))
#define loli ios::sync_with_stdio(0), cin.tie(0);
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
// https://zerojudge.tw/ShowProblem?problemid=c044

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<char, int>> v(26);
    for (int i = 0; i < 26; i++)
        v[i] = {i + 'A', 0};
    string s;
    while (getline(cin, s))
    {
        for (char c : s)
        {
            if (isalpha(c))
                v[toupper(c) - 'A'].S++;
        }
    }

    sort(v.begin(), v.end(), [](const pair<char, int> &a, const pair<char, int> &b)
         {
        if (a.S == b.S)
            return a.F < b.F;
        return a.S > b.S; });

    for (int i = 0; i < 26; i++)
        if (v[i].S)
            cout << v[i].F << " " << v[i].S << "\n";
}