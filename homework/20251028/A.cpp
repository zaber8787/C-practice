#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#include <iostream>
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define mem(x, y) memset((x), (y), sizeof(x))
#define loli ios::sync_with_stdio(0), cin.tie(0);
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
template <typename Ta, typename Tb>
istream &operator>>(istream &in, pair<Ta, Tb> &p) { return in >> p.first >> p.second; }
template <typename Ta, typename Tb>
ostream &operator<<(ostream &out, pair<Ta, Tb> &p) { return out << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
void arr_prll(T a, T b)
{
    T i = a;
    for (cout << *i++; i != b; i++)
        cout << " " << *i;
    cout << "\n";
}
ostream &prll() { return cout << "\n"; }
template <typename T>
ostream &prll(T a) { return cout << a << "\n"; }
template <typename T, typename... Args>
ostream &prll(T a, Args... args)
{
    cout << a << " ";
    return prll(args...);
}

//--------------------Main Code--------------------

ll count(ll n)
{
    ll sum = 0;
    while (true)
    {
        sum++;
        if (n == 1)
            break;
        if (n % 2 == 1)
            n = 3 * n + 1;
        else
            n /= 2;
    }
    return sum;
}

int main()
{
    loli ll n, m, temp1, temp2, Max = 0;
    while (cin >> n >> m)
    {
        Max = 0;
        temp1 = n;
        temp2 = m;
        if (n > m)
            swap(m, n);
        for (ll i = n; i <= m; i++)
        {
            if (count(i) > Max)
            {
                Max = count(i);
            }
        }
        cout << temp1 << " " << temp2 << " " << Max << "\n"
             << flush;
    }
}