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
// https://zerojudge.tw/ShowProblem?problemid=e575

int main()
{
    int t;
    cin >> t;
    for (int nmsl = 0; nmsl < t; nmsl++)
    {
        int m, n, q;
        cin >> m >> n >> q;
        print(m, n, q);
        cin.ignore();
        // 以 r 中心 找左上右下雙層 for
        vector<string> v(m);
        for (auto &i : v)
            getline(cin, i);
        for (int l = 0; l < q; l++)
        {
            pair<int, int> r;
            cin >> r.F >> r.S;
            char tar = v[r.F][r.S];
            pair<int, int> left = make_pair(r.F, r.S);
            pair<int, int> right = make_pair(r.F, r.S);
            int ans = 1;
            while (true)
            {
                left.F--;
                left.S--;
                right.F++;
                right.S++;
                bool check = true;
                if (left.F >= 0 && left.S >= 0 && right.F < m && right.S < n)
                {
                    for (int i = left.F; i <= right.F; i++)
                    {
                        if (!check)
                            break;
                        for (int j = left.S; j <= right.S; j++)
                        {
                            if (v[i][j] != tar)
                            {
                                check = false;
                                break;
                            }
                        }
                    }
                }
                else
                    check = false;

                if (check)
                    ans += 2;
                else
                    break;
            }
            print(ans);
        }
    }
}