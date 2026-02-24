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
    loli string s;
    while (getline(cin, s))
    {
        string num = "`1234567890-=", UP = "qwertyuiop[]\\", MID = "asdfghjkl;'", LOW = "zxcvbnm,./";
        string up_UP = "QWERTYUIOP", up_MID = "ASDFGHJKL", up_LOW = "ZXCVBNM";
        for (char c : s)
        {
            size_t pos;
            if (c == ' ')
                cout << c;
            else if ((pos = num.find(c)) != string::npos)
                cout << num[pos - 2];
            else if ((pos = UP.find(c)) != string::npos)
                cout << UP[pos - 2];
            else if ((pos = up_UP.find(c)) != string::npos)
                cout << UP[pos - 2];
            else if ((pos = MID.find(c)) != string::npos)
                cout << MID[pos - 2];
            else if ((pos = up_MID.find(c)) != string::npos)
                cout << MID[pos - 2];
            else if ((pos = LOW.find(c)) != string::npos)
                cout << LOW[pos - 2];
            else if ((pos = up_LOW.find(c)) != string::npos)
                cout << LOW[pos - 2];
        }
        cout << "\n";
    }
}