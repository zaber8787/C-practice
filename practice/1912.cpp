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
// https://tioj.ck.tp.edu.tw/problems/1912

int get_digit(int n)
{
    int cnt = 0;
    if (n < 10)
        return n;
    while (n > 0)
    {
        cnt += n % 10;
        n /= 10;
    }
    return get_digit(cnt);
}

int get_digit(const string &s)
{
    int cnt = 0;
    for (char c : s)
        cnt += c - '0';
    return get_digit(cnt);
}

void output(string n, int num, set<string> &ans)
{
    string tmp = n;
    for (int i = 0; i < tmp.size() + 1; i++)
        ans.insert(tmp.substr(0, i) + to_string(num) + tmp.substr(i));
}

int main()
{
    loli;
    int n, m;
    string digit;
    cin >> n >> m >> digit;
    int num;
    set<string> ans;
    for (int i = 0; i < 10; i++)
    {
        if (get_digit(digit + to_string(i)) == m)
        {
            num = i;
            output(digit, num, ans);
        }
    }
    int i = -1;
    for (const auto &s : ans)
    {
        i++;
        if (i == 0 || i == ans.size() - 1)
            continue;
        print(s);
    }
}