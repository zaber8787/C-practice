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
    int n, cnt = 0;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cnt++;
        // if (cnt != 1)
        //     print();
        cout << "Scenario #" << cnt << "\n";
        int m;
        int team = -1;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> m;
            int tmp;
            team++;
            for (int j = 0; j < m; j++)
            {
                cin >> tmp;
                mp[tmp] = team;
            }
        }

        queue<int> teams;
        vector<queue<int>> record(n);
        string s;
        while (cin >> s)
        {
            if (s == "ENQUEUE")
            {
                int tmp;
                cin >> tmp;
                int group = mp[tmp];
                if (record[group].empty())
                    teams.push(group);
                record[group].push(tmp);
            }
            else if (s == "DEQUEUE")
            {
                int group = teams.front();
                print(record[group].front());
                record[group].pop();
                if (record[group].empty())
                    teams.pop();
            }
            else if (s == "STOP")
                break;
        }
        print();
    }
}