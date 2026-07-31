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

vector<int> v;
int Min = 25;
void dfs(int idx, vector<bool> &line, int i, int cnt)
{
    if (i == v.size())
    {
        Min = min(cnt, Min);
        return;
    }
    int dis = v[i];
    i++;

    bool is_right_reachable = line[idx + dis], is_left_reachable = line[idx - dis];
    line[idx + dis] = 1;
    dfs(idx + dis, line, i, cnt + (is_right_reachable ? 0 : 1));

    line[idx + dis] = is_right_reachable;
    line[idx - dis] = 1;
    dfs(idx - dis, line, i, cnt + (is_left_reachable ? 0 : 1));
    line[idx - dis] = is_left_reachable;
}

int main()
{
    int m;
    cin >> m;
    v.resize(m);
    for (auto &i : v)
        cin >> i;
    vector<bool> line(5000000, 0);
    line[2499999] = 1;
    dfs(2499999, line, 0, 1);
    print(Min);
}