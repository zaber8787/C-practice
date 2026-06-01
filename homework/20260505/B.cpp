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

queue<tuple<int, int, int>> q;
vector<pii> cal(8);
void bfs(vector<vector<bool>> &v, tuple<int, int, int> n)
{
    for (pii i : cal)
    {
        pii coor(get<0>(n) + i.F, get<1>(n) + i.S);
        if (coor.F >= 0 && coor.F < 8 && coor.S >= 0 && coor.S < 8)
        {
            if (v[coor.F][coor.S])
                continue;
            v[coor.F][coor.S] = true;
            q.push({coor.F, coor.S, get<2>(n) + 1});
        }
    }
}

void process_cal()
{
    cal[0] = {-1, 2};
    cal[1] = {1, 2};
    cal[2] = {-1, -2};
    cal[3] = {1, -2};
    cal[4] = {-2, 1};
    cal[5] = {2, 1};
    cal[6] = {-2, -1};
    cal[7] = {2, -1};
    return;
}

int main()
{
    process_cal();
    string a, b;
    while (cin >> a >> b)
    {
        while (!q.empty())
            q.pop();
        vector<vector<bool>> v(8, vector<bool>(8, false));
        pii start, target;
        string tmp;
        start.F = int(a[0] - 'a');
        tmp = a.substr(1);
        start.S = stoi(tmp) - 1;
        target.F = int(b[0] - 'a');
        tmp = b.substr(1);
        target.S = stoi(tmp) - 1;
        q.push({start.F, start.S, 0});
        while (!q.empty())
        {
            if (get<0>(q.front()) == target.F && get<1>(q.front()) == target.S)
            {
                print("To get from", a, "to", b, "takes", get<2>(q.front()), "knight moves.");
                break;
            }
            bfs(v, q.front());
            q.pop();
        }
    }
}