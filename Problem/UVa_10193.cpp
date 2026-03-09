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
// https://zerojudge.tw/ShowProblem?problemid=d306

int binary_to_decimal(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res = res * 2 + (s[i] - '0');
    return res;
}

int get_int(int a, int b)
{
    if (b == 0)
        return a;
    while (a >= b)
    {
        a -= b;
    }
    return get_int(b, a);
}

int main()
{
    int n;
    string s1, s2;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        int num1 = binary_to_decimal(s1);
        int num2 = binary_to_decimal(s2);
        int ans = get_int(max(num1, num2), min(num1, num2));
        if (ans == 1)
            cout << "Pair #" << i + 1 << ": Love is not all you need!" << endl;
        else
            cout << "Pair #" << i + 1 << ": All you need is love!" << endl;
    }
}