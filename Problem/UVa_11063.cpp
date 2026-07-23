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
    int n, cnt = 0;
    while (cin >> n)
    {
        cnt++;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        bool check = 0;
        if (n < 1 || v[0] < 1)
            check = 1;
        for (int i = 1; i < n; i++)
            if (v[i] <= v[i - 1])
                check = 1;

        if (check)
        {
            cout << "Case #" << cnt << ": It is not a B2-Sequence.\n\n";
            continue;
        }
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (check)
                    break;
                if (st.find(v[i] + v[j]) != st.end())
                {
                    check = 1;
                    cout << "Case #" << cnt << ": It is not a B2-Sequence.\n\n";
                    break;
                }
                st.insert(v[i] + v[j]);
            }
        }
        if (!check)
            cout << "Case #" << cnt << ": It is a B2-Sequence.\n\n";
    }
}