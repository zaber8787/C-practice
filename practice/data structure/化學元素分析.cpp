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
// https://tioj.ck.tp.edu.tw/problems/2051

int get_digit(string s, int idx)
{
    int start = idx;
    while (idx + 1 < s.size() && isdigit(s[idx + 1]))
    {
        idx++;
    }
    int end = idx;
    return stoi(s.substr(start, end - start + 1));
}

void string_process(string s, map<string, int> &cnt, int times)
{
    int p = -1, q = -1, c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (p == -1)
                p = i;
            c++;
        }
        else if (s[i] == ')')
        {
            if (c == 1)
            {
                q = i;
                int tmp;
                string sub = s.substr(p + 1, q - p - 1);
                if (i + 1 < s.size() && isdigit(s[i + 1]))
                {
                    i++;
                    tmp = get_digit(s, i) * times;
                }
                else
                    tmp = 1;
                string_process(sub, cnt, tmp);
                p = -1, q = -1;
            }

            c--;
        }
        string key;
        if (isalpha(s[i]) && c == 0)
        {
            int ts;
            if (i + 1 < s.size() && isalpha(s[i + 1]) && islower(s[i + 1]))
            {
                key = s.substr(i, 2);
                i++;
            }
            else
                key = string(1, s[i]);

            if (i + 1 < s.size() && isdigit(s[i + 1]))
            {
                i++;
                cnt[key] += (get_digit(s, i)) * times;
            }
            else
                cnt[key] += times;
        }
    }
}

int main()
{
    loli;
    string s;
    cin >> s;
    map<string, int> cnt;
    string_process(s, cnt, 1);
    print(s);
    for (auto &p : cnt)
        cout << p.first << ":" << p.second << "\n";
}