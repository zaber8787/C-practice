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

int main()
{
    loli;
    pair<string, string> p;
    while (getline(cin, p.F), getline(cin, p.S))
    {
        vector<int> countF(26, 0), countS(26, 0);
        for (char c : p.F)
            if (isalpha(c))
                countF[c - 'a']++;
        for (char c : p.S)
            if (isalpha(c))
                countS[c - 'a']++;

        for (int i = 0; i < 26; i++)
        {
            int Min = min(countF[i], countS[i]);
            for (int j = 0; j < Min; j++)
            {
                cout << char('a' + i);
            }
        }
        cout << "\n";
    }
    return 0;
}