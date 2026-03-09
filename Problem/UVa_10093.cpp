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
// https://vjudge.net/problem/UVA-10093

int main()
{
    loli;
    string s;
    while (getline(cin, s))
    {
        long long sum = 0;
        int max_digit = 1;

        for (char c : s)
        {
            int v = -1;
            if (isdigit(c))
                v = c - '0';
            else if (isupper(c))
                v = c - 'A' + 10;
            else if (islower(c))
                v = c - 'a' + 36;

            if (v != -1)
            {
                sum += v;
                if (v > max_digit)
                    max_digit = v;
            }
        }

        bool found = false;
        for (int r = max_digit + 1; r <= 62; r++)
        {
            if (sum % (r - 1) == 0)
            {
                cout << r << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "such number is impossible!" << endl;
    }
}