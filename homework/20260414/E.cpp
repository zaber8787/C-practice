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
    long long n, m;
    while (cin >> n >> m)
    {
        int tmp = n, tmp1 = m;
        if (m == 0)
            m = 1;
        if (n == 0)
            n = 1;
        bool ck = true;
        for (int i = 2; i <= pow(m, 0.5); i++)
        {
            if (m % i == 0)
            {
                ck = false;
                break;
            }
        }
        if (ck && m > n)
        {
            cout << tmp1 << " does not divide " << tmp << "!\n";
            continue;
        }

        ck = false;
        unsigned long long ans = 1;
        for (int i = n; i > 0; i--)
        {
            ans *= i;
            if (ans % m == 0)
            {
                cout << tmp1 << " divides " << tmp << "!\n";
                ck = true;
                break;
            }
        }
        if (!ck)
            cout << tmp1 << " does not divide " << tmp << "!\n";
    }
}