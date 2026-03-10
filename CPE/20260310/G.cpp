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
    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++)
    {
        vector<int> cost(36);
        for (int i = 0; i < 36; i++)
            cin >> cost[i];

        int q;
        cin >> q;

        cout << "Case " << cs << ":\n";
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;

            int mn = INT_MAX;
            vector<int> ans;
            for (int base = 2; base <= 36; base++)
            {
                int val = x;
                int total = 0;

                if (val == 0)
                {
                    total = cost[0];
                }
                else
                {
                    while (val > 0)
                    {
                        total += cost[val % base];
                        val /= base;
                    }
                }

                if (total < mn)
                {
                    mn = total;
                    ans.clear();
                    ans.pb(base);
                }
                else if (total == mn)
                {
                    ans.pb(base);
                }
            }

            cout << "Cheapest base(s) for number " << x << ":";
            for (int b : ans)
                cout << " " << b;
            cout << "\n";
        }

        if (cs != t)
            cout << "\n";
    }
}