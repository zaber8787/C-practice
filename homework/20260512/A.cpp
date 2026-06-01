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

bool is_prime(int n)
{
    for (int i = 2; i <= pow(n, 0.5); i++)
        if (n % i == 0)
            return false;
    return true;
}

void dfs(vector<bool> v, vector<int> ans)
{

    for (int i = 2; i <= v.size() - 1; i++)
    {
        if (v[i])
            continue;
        if (is_prime(i + ans.back()))
        {
            ans.pb(i);
            v[i] = true;
            if (ans.size() == v.size() - 1)
                for (int j : ans)
                    if (j != ans.back())
                        cout << j << " ";
                    else
                        cout << j << "\n";
            else
                dfs(v, ans);
        }
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<bool> v(n + 1, false);
        v[0] = true;
        v[1] = true;
        vector<int> ans;
        ans.pb(1);
        dfs(v, ans);
    }
}