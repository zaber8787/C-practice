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

int to_dec(string &s)
{
    int x = 0;
    for (char c : s)
        x = x * 2 + (c - '0');
    return x;
}

int main()
{
    loli;
    int n;
    cin >> n;

    for (int k = 1; k <= n; k++)
    {
        string s1, s2;
        cin >> s1 >> s2;

        int a = to_dec(s1);
        int b = to_dec(s2);

        if (gcd(a, b) > 1)
            cout << "Pair #" << k << ": All you need is love!\n";
        else
            cout << "Pair #" << k << ": Love is not all you need!\n";
    }
}