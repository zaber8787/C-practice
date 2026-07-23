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

bool issignal(char c)
{
    if (c == '+' || c == '-')
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        int tmp = s.find('=');
        string F, S;
        F = s.substr(0, tmp);
        S = s.substr(tmp + 1);
        int x = 0;
        int normal = 0;
        int ptr = -1;
        for (int j = 0; j < F.size(); j++)
        {
            if (issignal(F[j]))
            {
                if (j == 0)
                {
                    ptr = 0;
                    continue;
                }
                string temp = F.substr(ptr + 1, j - ptr - 1);
                if (temp.back() == 'x')
                {
                    if (temp.size() == 1)
                        temp = "1x";
                    if (ptr != -1 && F[ptr] == '-')
                        x -= stoi(temp.substr(0, temp.size() - 1));
                    else
                        x += stoi(temp.substr(0, temp.size() - 1));
                    // print(x);
                }
                else
                {
                    if (ptr != -1 && F[ptr] == '-')
                        normal += stoi(temp);
                    else
                        normal -= stoi(temp);
                    // print(normal);
                }
                ptr = j;
            }
            else if (j == F.size() - 1)
            {
                string temp = F.substr(ptr + 1, j - ptr);
                if (temp.back() == 'x')
                {
                    if (temp.size() == 1)
                        temp = "1x";
                    if (ptr != -1 && F[ptr] == '-')
                        x -= stoi(temp.substr(0, temp.size() - 1));
                    else
                        x += stoi(temp.substr(0, temp.size() - 1));
                    // print(x);
                }
                else
                {
                    if (ptr != -1 && F[ptr] == '-')
                        normal += stoi(temp);
                    else
                        normal -= stoi(temp);
                    // print(normal);
                }
                ptr = j;
            }
        }
        ptr = -1;
        for (int j = 0; j < S.size(); j++)
        {
            if (issignal(S[j]))
            {
                if (j == 0)
                {
                    ptr = 0;
                    continue;
                }
                string temp = S.substr(ptr + 1, j - ptr - 1);
                if (temp.back() == 'x')
                {
                    if (temp.size() == 1)
                        temp = "1x";
                    if (ptr != -1 && S[ptr] == '-')
                        x += stoi(temp.substr(0, temp.size() - 1));
                    else
                        x -= stoi(temp.substr(0, temp.size() - 1));
                    // print(x);
                }
                else
                {
                    if (ptr != -1 && S[ptr] == '-')
                        normal -= stoi(temp);
                    else
                        normal += stoi(temp);
                    // print(normal);
                }
                ptr = j;
            }
            else if (j == S.size() - 1)
            {
                string temp = S.substr(ptr + 1, j - ptr);
                if (temp.back() == 'x')
                {
                    if (temp.size() == 1)
                        temp = "1x";
                    if (ptr != -1 && S[ptr] == '-')
                        x += stoi(temp.substr(0, temp.size() - 1));
                    else
                        x -= stoi(temp.substr(0, temp.size() - 1));
                    // print(x);
                }
                else
                {
                    if (ptr != -1 && S[ptr] == '-')
                        normal -= stoi(temp);
                    else
                        normal += stoi(temp);
                    // print(normal);
                }
                ptr = j;
            }
        }
        if (x != 0)
        {
            int ans = (int)floor((double)normal / x);
            print(ans);
        }
        else if (normal != 0)
            print("IMPOSSIBLE");
        else
            print("IDENTITY");
    }
}