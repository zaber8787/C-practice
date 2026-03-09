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
// https://zerojudge.tw/ShowProblem?problemid=a741

void solve(long long n)
{
    if (n >= 10000000)
    {
        solve(n / 10000000); // 遞迴：處理「億」以上
        cout << " kuti";
        n %= 10000000;
    }
    if (n >= 100000)
    {
        solve(n / 100000); // 處理「十萬」
        cout << " lakh";
        n %= 100000;
    }
    if (n >= 1000)
    {
        solve(n / 1000); // 處理「千」
        cout << " hajar";
        n %= 1000;
    }
    if (n >= 100)
    {
        solve(n / 100); // 處理「百」
        cout << " shata";
        n %= 100;
    }
    if (n > 0)
    {
        cout << " " << n; // 處理剩下的 1-99
    }
}

int main()
{
    long long n, kase = 1;
    while (cin >> n)
    {
        // 格式要求：編號佔 4 格，右對齊
        cout << setw(4) << kase++ << ".";

        if (n == 0)
            cout << " 0";
        else
            solve(n);

        cout << endl;
    }
    return 0;
}
