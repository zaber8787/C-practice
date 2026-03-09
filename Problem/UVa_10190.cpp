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
// https://zerojudge.tw/ShowProblem?problemid=e566

int main()
{
    loli;
    long long n, m;
    while (cin >> n >> m)
    {
        vector<long long> v;
        v.pb(n);
        bool ck = false;
        while (n != 1)
        {
            if (m == 0)
            {
                ck = true;
                break;
            }
            if (n % m == 0)
                n /= m;
            else
            {
                ck = true;
                break;
            }
            if (n / m == n)
            {
                ck = true;
                break;
            }
            v.pb(n);
        }
        if (ck)
            print("Boring!");
        else
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << (i == v.size() - 1 ? "\n" : " ");
    }
}