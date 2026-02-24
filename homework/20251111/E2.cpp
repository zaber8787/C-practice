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

int main()
{
    loli ll n, Max = -999999999999999, sum = 0;
    cin >> n;
    ll v[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i]; // 紀錄 array
    }
    for (ll i = 0; i < n; i++) // 遍歷一次 array
    {
        sum = 0;
        for (ll j = i; j < n; j++)
        {
            sum += v[j];         // 遍歷從第 i 個開始的每個子集，加上前面的遍歷就會有所有連續子集
            Max = max(Max, sum); // 檢查是否比當前最大還大，全部檢查一次相當於檢查所有子集
        }
    }
    cout << Max << "\n"; // 輸出最大值
}