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

int Month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string Day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

string f(int m, int d)
{
    if (m == 4)
    {
        if (d >= 4)
            return Day[(d - 4) % 7];
        else
            return Day[(7 - (4 - d) % 7) % 7];
    }
    if (m < 4)
    {
        int days = 0;
        for (int i = m + 1; i < 4; i++)
            days += Month[i - 1];
        days += 4;
        days += (Month[m - 1] - d);
        return Day[(7 - (days % 7)) % 7];
    }

    int days = 0;
    for (int i = 5; i < m; i++)
        days += Month[i - 1];
    days += 26;
    days += d;
    return Day[days % 7];
}

int main()
{
    loli;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, d;
        cin >> m >> d;
        string s = f(m, d);
        print(s);
    }
}