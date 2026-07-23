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
// https://zerojudge.tw/ShowProblem?problemid=e516

void north(vector<int> &v)
{
    int temp = v[1];
    v[1] = v[0];
    v[0] = v[3];
    v[3] = v[2];
    v[2] = temp;
    return;
}

void south(vector<int> &v)
{
    int temp = v[3];
    v[3] = v[0];
    v[0] = v[1];
    v[1] = v[2];
    v[2] = temp;
    return;
}

void east(vector<int> &v)
{
    int temp = v[5];
    v[5] = v[0];
    v[0] = v[4];
    v[4] = v[2];
    v[2] = temp;
    return;
}

void west(vector<int> &v)
{
    int temp = v[4];
    v[4] = v[0];
    v[0] = v[5];
    v[5] = v[2];
    v[2] = temp;
    return;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (!n)
            break;
        vector<int> v = {1, 2, 6, 5, 3, 4};
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (s == "north")
                north(v);
            if (s == "south")
                south(v);
            if (s == "east")
                east(v);
            if (s == "west")
                west(v);
        }
        print(v[0]);
    }
}