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

char turn(char face, char c)
{
    vector<char> v = {'N','E','S','W'};
    int idx;
    for (int i = 0; i < 4; i++)
    {
        if (v[i] == face)
        {
            idx = i;
            break;
        }
    }

    if (c == 'R')
    {
        idx++;
        if (idx == 4)
            idx = 0;
    }
    if (c == 'L')
    {
        idx--;
        if (idx == -1)
            idx = 3;
    }
    return v[idx];
}

pii move(pii coord, char face)
{
    if (face == 'N')
        coord.S++;
    else if (face == 'E')
        coord.F++;
    else if (face == 'S')
        coord.S--;
    else if (face == 'W')
        coord.F--;
    return coord;
}

int main()
{
    loli;
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> ck(n + 1, vector<bool>(m + 1, false));
    pii edge = make_pair(n, m);
    char face;
    while (cin >> n >> m >> face)
    {
        bool lost = false;
        pii coord = make_pair(n, m);
        string s;
        cin >> s;
        for (char i : s)
        {
            if (i == 'F')
            {
                pii temp = coord;
                temp = move(coord, face);
                if (temp.F < 0 || temp.S < 0 || temp.F > n || temp.S > m)
                {
                    if (ck[coord.F][coord.S])
                        continue;
                    else
                    {
                        lost = true;
                        ck[coord.F][coord.S] = true;
                        break;
                    }
                }
            }
            else
                face = turn(face, i);
        }
        if (lost)
            cout << coord.F << " " << coord.S << " " << face << " " << "LOST\n";
        else
            print(coord.F, coord.S, face);
    }
}