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

string fib_repr(long long x, const vector<long long> &v)
{
    // 找到最大的 v[idx] <= x
    int idx = int(upper_bound(v.begin(), v.end(), x) - v.begin()) - 1;
    string s;
    s.reserve(idx + 1);
    for (int k = idx; k >= 0; --k)
    {
        if (x >= v[k])
        {
            s.push_back('1');
            x -= v[k];
        }
        else
            s.push_back('0');
    }
    return s;
}

int main()
{
    loli;
    vector<ll> v;
    v.push_back(1);
    v.push_back(2);
    while (v.back() <= 100000000) // 依題目上限產生足夠的 Fibonacci
        v.push_back(v.back() + v[v.size() - 2]);

    ll n;
    if (!(cin >> n))
        return 0;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        cout << x << " = " << fib_repr(x, v) << " (fib)\n";
    }
}