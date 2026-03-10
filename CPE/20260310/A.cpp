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
    int n, c;
    while (cin >> n >> c)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            bool prime = true;
            if (i > 1)
            {
                for (int j = 2; j * j <= i; j++)
                {
                    if (i % j == 0)
                    {
                        prime = false;
                        break;
                    }
                }
            }
            if (prime)
            {
                v.pb(i);
            }
        }
        cout << n << " " << c << ":";
        int sz = (int)v.size();
        int take = (sz % 2 == 0 ? 2 * c : 2 * c - 1);
        if (take > sz)
            take = sz;

        int start = (sz - take) / 2;
        for (int j = start; j < start + take; j++)
        {
            cout << " " << v[j];
        }
        cout << "\n\n";
    }
}