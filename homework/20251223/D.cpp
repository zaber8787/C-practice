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
    loli int n, m, cnt = 1;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        string s;
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                if (s[j] == '*')
                {
                    v[i][j] = -1;
                    if (i - 1 >= 0 && v[i - 1][j] != -1)
                        v[i - 1][j]++;
                    if (i + 1 < n && v[i + 1][j] != -1)
                        v[i + 1][j]++;
                    if (j - 1 >= 0 && v[i][j - 1] != -1)
                        v[i][j - 1]++;
                    if (j + 1 < m && v[i][j + 1] != -1)
                        v[i][j + 1]++;
                    if (i - 1 >= 0 && j - 1 >= 0 && v[i - 1][j - 1] != -1)
                        v[i - 1][j - 1]++;
                    if (i - 1 >= 0 && j + 1 < m && v[i - 1][j + 1] != -1)
                        v[i - 1][j + 1]++;
                    if (i + 1 < n && j - 1 >= 0 && v[i + 1][j - 1] != -1)
                        v[i + 1][j - 1]++;
                    if (i + 1 < n && j + 1 < m && v[i + 1][j + 1] != -1)
                        v[i + 1][j + 1]++;
                }
            }
        }
        if (cnt > 1)
            cout << "\n";
        cout << "Field #" << cnt++ << ":\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == -1)
                    cout << '*';
                else
                    cout << v[i][j];
            }
            cout << "\n";
        }
    }
}