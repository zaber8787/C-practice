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

int carry(int n, int m, int temp)
{
    if (n == 0 && m == 0)
        return 0;
    if (n % 10 + m % 10 + temp >= 10)
        temp = 1;
    else
        temp = 0;
    return temp + carry(n / 10, m / 10, temp);
}

int main()
{
    loli int n, m, ans;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        ans = carry(n, m, 0);
        if (ans == 0)
            cout << "NO carry operation.\n"
                 << flush;
        else if (ans == 1)
            cout << "1 carry operation.\n"
                 << flush;
        else
            cout << ans << " carry operations.\n"
                 << flush;
    }
}