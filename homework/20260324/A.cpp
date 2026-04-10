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
    vector<long long> B(3);
    vector<long long> G(3);
    vector<long long> C(3);
    while (cin >> B[0] >> G[0] >> C[0] >> B[1] >> G[1] >> C[1] >> B[2] >> G[2] >> C[2])
    {
        long long Min = LONG_LONG_MAX, ans;
        long long total = accumulate(ALL(B), 0) + accumulate(ALL(G), 0) + accumulate(ALL(C), 0);
        long long tmp;
        for (int i = 0; i < 2; i++)
        {
            tmp = total - B[0] - C[i + 1] - G[2 - i];

            if (tmp <= Min)
            {
                ans = ((i < ans && tmp == Min) || tmp < Min) ? i : ans;
                Min = tmp;
            }
            tmp = total - C[0] - B[i + 1] - G[2 - i];

            if (tmp <= Min)
            {
                ans = ((i + 2 < ans && tmp == Min) || tmp < Min) ? i + 2 : ans;
                Min = tmp;
            }
            tmp = total - C[2 - i] - B[i + 1] - G[0];

            if (tmp <= Min)
            {
                ans = ((i + 4 < ans && tmp == Min) || tmp < Min) ? i + 4 : ans;
                Min = tmp;
            }
        }
        if (ans == 0)
            print("BCG", Min);
        else if (ans == 1)
            print("BGC", Min);
        else if (ans == 2)
            print("CBG", Min);
        else if (ans == 3)
            print("CGB", Min);
        else if (ans == 4)
            print("GBC", Min);
        else
            print("GCB", Min);
    }
}
