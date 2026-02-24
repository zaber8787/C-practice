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

int main()
{
    loli ll n, Max = -999999999999999, sum = 0;
    cin >> n;
    ll v[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        Max = max(Max, v[i]);
        sum += v[i];
    }
    Max = max(Max, sum);
    for (ll i = 2; i <= n - 1; i++)
    {
        sum = 0;
        for (ll k = 0; k < i; k++)
            sum += v[k];
        Max = max(Max, sum);
        for (ll j = 0; j < n - i; j++)
        {
            sum = sum - v[j] + v[j + i];
            Max = max(Max, sum);
        }
    }
    cout << Max << "\n"
         << flush;
}