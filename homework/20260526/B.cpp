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
    int gs = 0;
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
    if (ans.Bscore > ans.Ascore)
    {
        swap(ans.teamA, ans.teamB);
        swap(ans.Bscore, ans.Ascore);
    }

    return ans;
}

string lower_string(string s)
{
    for (auto &i : s)
        if (isalpha(i))
            i = tolower(i);
    return s;
}

bool cmp(team a, team b)
{
    if (a.tp < b.tp)
        return false;
    if (a.tp > b.tp)
        return true;
    if (a.win < b.win)
        return false;
    if (a.win > b.win)
        return true;
    if ((a.gs - a.ga) < (b.gs - b.ga))
        return false;
    if ((a.gs - a.ga) > (b.gs - b.ga))
        return true;
    if (a.gs < b.gs)
        return false;
    if (a.gs > b.gs)
        return true;
    if (a.gp > b.gp)
        return false;
    if (a.gp < b.gp)
        return true;
    if (lower_string(a.name) > lower_string(b.name))
        return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string name;
        getline(cin, name);
        int tmp;
        cin >> tmp;
        cin.ignore();
        vector<team> teams(tmp);
        for (auto &j : teams)
            getline(cin, j.name);
        cin >> tmp;
        cin.ignore();
        string s;
        for (int j = 0; j < tmp; j++)
        {
            getline(cin, s);
            result temp = game_analyze(s);
            for (auto &k : teams)
            {
                if (k.name != temp.teamA)
                    continue;
                k.gs += temp.Ascore;
                k.gp++;
                k.ga += temp.Bscore;
                if (temp.Ascore == temp.Bscore)
                {
                    k.tp++;
                    k.tie++;
                }
                else
                {
                    k.win++;
                    k.tp += 3;
                }
            }
            for (auto &k : teams)
            {
                if (k.name != temp.teamB)
                    continue;
                k.gs += temp.Bscore;
                k.gp++;
                k.ga += temp.Ascore;
                if (temp.Ascore == temp.Bscore)
                {
                    k.tp++;
                    k.tie++;
                }
                else
                    k.lost++;
            }
        }
        sort(teams.begin(), teams.end(), cmp);
        print(name);
        for (int j = 0; j < teams.size(); j++)
        {
            cout << j + 1 << ") " << teams[j].name << " " << teams[j].tp << "p, " << teams[j].gp << "g (" << teams[j].win << "-" << teams[j].tie << "-" << teams[j].lost << "), " << teams[j].gs - teams[j].ga << "gd (" << teams[j].gs << "-" << teams[j].ga << ")\n";
        }
    }
}