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
    loli vector<int> v(4);
    int c;
    cin >> c;
    for (int i = 1; i <= c; i++)
    {
        cin >> v[0] >> v[1] >> v[2] >> v[3];
        int cnt = 0;
        while (v[0] != v[2] || v[1] != v[3])
        {
            if (v[1] == 0)
            {
                v[1] = v[0] + 1;
                v[0] = 0;
            }
            else
            {
                v[0]++;
                v[1]--;
            }
            cnt++;
        }
        cout << "Case " << i << ": " << cnt << "\n"
             << flush;
    }
}