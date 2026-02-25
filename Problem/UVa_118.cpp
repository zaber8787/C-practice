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
// https://zerojudge.tw/ShowProblem?problemid=c082

char get_dest(pii v)
{
    if (v == MP(0, 1))
        return 'N';
    else if (v == MP(0, -1))
        return 'S';
    else if (v == MP(1, 0))
        return 'E';
    else
        return 'W';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int longs, shorts, a, b, tempF, tempS;
    cin >> longs >> shorts;
    char dest;
    string cmd;
    set<pii> lost;
    bool alive = true;

    while (cin >> a >> b >> dest >> cmd)
    {
        alive = true;
        pii v, ans = MP(a, b);

        if (dest == 'N')
            v = MP(0, 1);
        else if (dest == 'S')
            v = MP(0, -1);
        else if (dest == 'E')
            v = MP(1, 0);
        else
            v = MP(-1, 0);

        for (int i = 0; i < cmd.size(); i++)
        {
            if (cmd[i] == 'R')
                v = MP(v.S, -v.F);
            else if (cmd[i] == 'L')
                v = MP(-v.S, v.F);
            else
            {
                tempF = ans.F + v.F;
                tempS = ans.S + v.S;
                if (tempF < 0 || tempF > longs || tempS < 0 || tempS > shorts)
                {
                    if (lost.find(ans) == lost.end())
                    {
                        lost.insert(ans);
                        cout << ans.F << " " << ans.S << " " << get_dest(v) << " LOST\n";
                        alive = false;
                        break;
                    }
                    else
                        continue;
                }
                else
                {
                    ans.F = tempF;
                    ans.S = tempS;
                }
            }
        }
        if (alive)
            cout << ans.F << " " << ans.S << " " << get_dest(v) << "\n";
    }
}