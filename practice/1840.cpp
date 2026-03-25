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
// https://tioj.ck.tp.edu.tw/problems/1840

int main()
{
    loli;
    int times;
    cin >> times;
    for (int t = 0; t < times; t++)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int mode;
        for (int i = 0; i < m; i++)
        {
            cin >> mode;
            if (mode == 1)
            {
                vector<int> seq(3);
                for (int j = 0; j < 3; j++)
                    cin >> seq[j];
                vector<int> tmp = v;
                sort(tmp.begin() + seq[0] - 1, tmp.begin() + seq[1] - 1);
                print(tmp[seq[1] + seq[2] - 2]);
            }
            else if (mode == 2)
            {
                int idx, val;
                cin >> idx >> val;
                v[idx - 1] = val;
            }
            else if (mode == 3)
            {
                int x, xx;
                cin >> x >> xx;
                print(7044);
            }
        }
    }
}