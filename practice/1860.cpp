#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#include <bits/stdc++.h>
#include "lib1860.h"
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
    double e = exp(-1);
    int T = Start_The_Loli_Dream();
    for (int i = 0; i < T; i++)
    {
        int N = Count_How_Many_Loli();
        int Max = INT_MIN;
        int standard = double(N) * e;
        for (int j = 1; j <= N; j++)
        {
            int x = Get_Loli_Moeness();
            if (j <= standard)
            {
                Max = max(Max, x);
            }
            else
            {
                if (x > Max)
                {
                    You_Choose_This_Loli();
                    break;
                }
                if (j == N)
                {
                    You_Choose_This_Loli();
                }
            }
        }
    }
}