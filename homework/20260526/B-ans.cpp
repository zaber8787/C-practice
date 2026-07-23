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

//--------------------Main Code--------------------

struct team
{
    string name;
    int points = 0;
    int games = 0;
    int wins = 0;
    int ties = 0;
    int losses = 0;
    int goal_diff = 0;
    int goals_scored = 0;
    int goals_against = 0;

    string lower_name() const
    {
        string res = name;
        for (char &c : res)
            c = tolower(c);
        return res;
    }
};

bool cmp(const team &a, const team &b)
{
    if (a.points != b.points)
        return a.points > b.points;
    if (a.wins != b.wins)
        return a.wins > b.wins;
    if (a.goal_diff != b.goal_diff)
        return a.goal_diff > b.goal_diff;
    if (a.goals_scored != b.goals_scored)
        return a.goals_scored > b.goals_scored;
    if (a.games != b.games)
        return a.games < b.games;
    return a.lower_name() < b.lower_name();
}

int main()
{
    loli;
    int n;
    if (!(cin >> n))
        return 0;
    string dummy;
    getline(cin, dummy);
    for (int idx = 0; idx < n; idx++)
    {
        if (idx > 0)
            cout << "\n";
        string tournament;
        getline(cin, tournament);

        int t;
        cin >> t;
        getline(cin, dummy);
        map<string, int> name2id;
        vector<team> teams(t);
        for (int i = 0; i < t; i++)
        {
            getline(cin, teams[i].name);
            name2id[teams[i].name] = i;
        }

        int g;
        cin >> g;
        getline(cin, dummy);
        for (int i = 0; i < g; i++)
        {
            string game;
            getline(cin, game);
            int p1 = game.find('#');
            int p2 = game.find('@');
            int p3 = game.find('#', p2 + 1);

            string tA = game.substr(0, p1);
            int scoreA = stoi(game.substr(p1 + 1, p2 - p1 - 1));
            int scoreB = stoi(game.substr(p2 + 1, p3 - p2 - 1));
            string tB = game.substr(p3 + 1);

            int idA = name2id[tA];
            int idB = name2id[tB];

            teams[idA].games++;
            teams[idB].games++;
            teams[idA].goals_scored += scoreA;
            teams[idB].goals_scored += scoreB;
            teams[idA].goals_against += scoreB;
            teams[idB].goals_against += scoreA;
            teams[idA].goal_diff += (scoreA - scoreB);
            teams[idB].goal_diff += (scoreB - scoreA);

            if (scoreA > scoreB)
            {
                teams[idA].wins++;
                teams[idB].losses++;
                teams[idA].points += 3;
            }
            else if (scoreA < scoreB)
            {
                teams[idB].wins++;
                teams[idA].losses++;
                teams[idB].points += 3;
            }
            else
            {
                teams[idA].ties++;
                teams[idB].ties++;
                teams[idA].points += 1;
                teams[idB].points += 1;
            }
        }

        sort(ALL(teams), cmp);

        cout << tournament << "\n";
        for (int i = 0; i < t; i++)
        {
            cout << i + 1 << ") " << teams[i].name << " "
                 << teams[i].points << "p, "
                 << teams[i].games << "g ("
                 << teams[i].wins << "-" << teams[i].ties << "-" << teams[i].losses << "), "
                 << teams[i].goal_diff << "gd ("
                 << teams[i].goals_scored << "-" << teams[i].goals_against << ")\n";
        }
    }
    return 0;
}