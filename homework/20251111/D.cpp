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

bool is_prime(int a)
{
    if (a == 1)
        return false;
    if (a == 2)
        return true;
    for (int i = 2; i <= pow(a, 0.5); i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    loli ll n;
    while (cin >> n)
    {
        int cnt = 0;
        if (n == 0)
            break;
        for (int i = 2; i < n / 2 + 1; i++)
        {
            if (!is_prime(i))
                continue;
            if (is_prime(n - i))
                cnt++;
        }
        cout << cnt << "\n"
             << flush;
    }
}