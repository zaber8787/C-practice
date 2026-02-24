#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ll long long

bool check(char a, char b)
{
    if (a == 'R' && b == 'S')
        return true;
    if (a == 'S' && b == 'P')
        return true;
    if (a == 'P' && b == 'R')
        return true;
    return false;
}

vector<vector<char>> land(vector<vector<char>> v)
{
    int r = v.size();
    int c = v[0].size();
    vector<vector<char>> ans = v;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int left = j - 1, top = r - 1, right = j + 1, bottom = i + 1;
            if (left >= 0 && check(v[i][j], v[i][left]))
                ans[i][left] = v[i][j];
            if (top >= 0 && check(v[i][j], v[top][j]))
                ans[top][j] = v[i][j];
            if (right < c && check(v[i][j], v[i][right]))
                ans[i][right] = v[i][j];
            if (bottom < r && check(v[i][j], v[bottom][j]))
                ans[bottom][j] = v[i][j];
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int r, c, n;
        cin >> r >> c >> n;
        vector<vector<char>> v(r, vector<char>(c));
        string s;
        for (int j = 0; j < r; j++)
        {
            cin >> s;
            for (int k = 0; k < c; k++)
            {
                v[j][k] = s[k];
            }
        }
        for (int j = 0; j < n; j++)
        {
            v = land(v);
        }
        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cout << v[j][k];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}