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
int prior(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int main()
{
    loli;
    int n;
    cin >> n;
    cin.ignore();
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        vector<char> v;
        while (getline(cin, s))
        {
            if (s.empty())
                break;
            v.pb(s[0]);
        }
        string result;
        stack<char> st;
        for (auto j : v)
        {
            if (isdigit(j))
            {
                result += j;
            }
            else if (j == '(')
            {
                st.push(j);
            }
            else if (j == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }
            else
            {
                while (!st.empty() && prior(st.top()) >= prior(j))
                {
                    result += st.top();
                    st.pop();
                }
                st.push(j);
            }
        }
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        print(result);
        print();
    }
}