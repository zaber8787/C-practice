#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ll long long

int f(int n)
{
    if (n < 10)
        return n;
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return f(sum);
}

int g(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            sum += (s[i] - 'a' + 1);
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            sum += (s[i] - 'A' + 1);
        }
    }
    return f(sum);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string name1, name2;
    cin >> name1 >> name2;
    int sum1 = 0, sum2 = 0;
    sum1 = g(name1);
    sum2 = g(name2);
    float ans = float(min(sum1, sum2)) / float(max(sum1, sum2)) * 10000;
    ans = round(ans) / 100;
    cout << fixed << setprecision(2) << ans << "%";
}