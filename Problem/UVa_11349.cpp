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
    loli;
    int n;
    cin >> n;
    for (int t = 1; t <= n; t++)
    {
        string temp, tmp;
        int size;
        cin >> temp >> tmp >> size;

        vector<vector<ll>> v(size, vector<ll>(size));
        bool ok = true;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> v[i][j];
                if (v[i][j] < 0)
                {
                    ok = false;
                }
            }
        }

        if (ok)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (v[i][j] != v[size - 1 - i][size - 1 - j])
                    {
                        ok = false;
                    }
                }
            }
        }

        if (ok)
            cout << "Test #" << t << ": Symmetric.\n";
        else
            cout << "Test #" << t << ": Non-symmetric.\n";
    }
}
