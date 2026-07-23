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
// https://cses.fi/problemset/task/1634

vector<int> coins, ans;
int INF = 1e9 + 7;
int solve(int n)
{
    if (n == 0)
        return 0;
    if (n < coins[0])
        return INF;
    if (ans[n] != -1)
        return ans[n];
    int tmp = INF;
    for (int &i : coins)
    {
        if (i > n)
            break;
        int ck = solve(n - i);
        if (ck != INF)
            tmp = min(tmp, 1 + ck);
    }
    ans[n] = tmp;
    return ans[n];
}

int main()
{
    int n, x;
    cin >> n >> x;

    coins.resize(n);
    ans.resize(x + 1, -1);

    for (int &i : coins)
        cin >> i;
    sort(ALL(coins));
    print(solve(x) < INF ? solve(x) : -1);
}