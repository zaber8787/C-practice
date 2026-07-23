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
// https://zerojudge.tw/ShowProblem?problemid=e531

int main()
{
    map<char, int> mp;
    mp['c'] = 463;
    mp['d'] = 462;
    mp['e'] = 460;
    mp['f'] = 456;
    mp['g'] = 448;
    mp['a'] = 384;
    mp['b'] = 256;
    mp['C'] = 128;
    mp['D'] = 974;
    mp['E'] = 972;
    mp['F'] = 968;
    mp['G'] = 960;
    mp['A'] = 896;
    mp['B'] = 768;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        vector<int> cnt(10, 0);
        bitset<10> finger(false);
        string s;
        getline(cin, s);
        for (char c : s)
        {
            int temp = mp[c];
            for (int j = 9; j >= 0; j--)
            {
                if (temp % 2)
                {
                    if (!finger[j])
                    {
                        cnt[j]++;
                        finger[j] = true;
                    }
                }
                else
                    finger[j] = false;
                temp /= 2;
            }
        }
        for (int j = 0; j < 10; j++)
            cout << cnt[j] << (j == 9 ? "" : " ");
        cout << "\n";
    }
}