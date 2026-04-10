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

int main()
{
    int n, b;
    vector<char> v = {'A', 'B', 'C', 'D', 'E'};
    while (cin >> b >> n)
    {
        for (int j = 0; j < n; j++)
        {
            if (b == 1)
            {
                char tmp = v[0];
                for (int i = 0; i < 4; i++)
                    v[i] = v[i + 1];
                v[4] = tmp;
            }
            if (b == 2)
            {
                char tmp = v.back();
                for (int i = 4; i > 0; i--)
                    v[i] = v[i - 1];
                v[0] = tmp;
            }
            if (b == 3)
                swap(v[0], v[1]);
            if (b == 4)
            {
                print(v[0], v[1], v[2], v[3], v[4]);
                break;
            }
        }
    }
}