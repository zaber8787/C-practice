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

struct team
{
    string name;
    int rank;
    int tp = 0;
    int gp = 0;
    int win = 0;
    int tie = 0;
    int lost = 0;
    int ga = 0;
};

struct result
{
    string teamA;
    string teamB;
    int Ascore;
    int Bscore;
};

result game_analyze(string s)
{
    result ans;
    int ptr = 0;

    while (s[ptr] != '#')
        ptr++;
    ans.teamA = s.substr(0, ptr);

    int tmp = ++ptr;
    while (s[ptr] != '@')
        ptr++;
    ans.Ascore = stoi(s.substr(tmp, ptr - tmp));

    tmp = ++ptr;
    while (s[ptr] != '#')
        ptr++;
    ans.Bscore = stoi(s.substr(tmp, ptr - tmp));

    ptr++;
    ans.teamB = s.substr(ptr, s.size() - ptr);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        getline(cin, name);
        int tmp;
        cin >> tmp;
        vector<team> teams(t);
        for (auto j : teams)
            getline(cin, j.name);
        cin >> tmp;
        string s;
        for (int j = 0; j < n; j++)
        {
            getline(cin, s);
        }
    }
}