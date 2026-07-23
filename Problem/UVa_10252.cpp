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
// https://zerojudge.tw/ShowProblem?problemid=e507

int main()
{
    string s, s1;
    while (getline(cin, s), getline(cin, s1))
    {
        vector<int> alpha(26, 0), alpha1(26, 0);
        for (auto i : s)
            alpha[int(i) - 'a']++;
        for (auto i : s1)
            alpha1[int(i) - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < min(alpha[i], alpha1[i]); j++)
                cout << char('a' + i);
        }
        cout << "\n";
    }
}