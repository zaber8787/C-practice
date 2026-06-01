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

int m, n, q;

int main()
{
    loli;
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cin >> m >> n >> q;
        print(m, n, q);
        vector<vector<char>> v(m, vector<char>(n));
        string s;
        for (int i = 0; i < m; i++)
        {
            cin >> s;
            for (int j = 0; j < n; j++)
                v[i][j] = s[j];
        }
        for (int i = 0; i < q; i++)
        {
            int a, b;
            cin >> a >> b;
            int ans = 1;
            char center = v[a][b];
            for (int r = 1;; r++)
            {
                bool ok = true;
                int up = a - r, down = a + r;
                int left = b - r, right = b + r;

                // 1. 檢查是否超出地圖邊界
                if (up < 0 || down >= m || left < 0 || right >= n)
                    break;

                // 2. 檢查這一圈 r 的正方形邊框是否都等於 center
                for (int row = up; row <= down; row++)
                {
                    for (int col = left; col <= right; col++)
                    {
                        if (v[row][col] != center)
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok)
                        break;
                }

                if (ok)
                    ans = 2 * r + 1; // 更新目前最大的合法邊長
                else
                    break; // 這一圈失敗，更外面也不可能成功
            }
            print(ans);
        }
    }
}