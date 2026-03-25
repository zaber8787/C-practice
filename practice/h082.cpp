#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#include <bits/stdc++.h>
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define mem(x, y) memset((x), (y), sizeof(x))
#define loli ios::sync_with_stdio(0), cin.tie(0);
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
// https://zerojudge.tw/ShowProblem?problemid=h082

bool compare(long long a, long long b, long long c, long long d)
{
    if (a * b >= c * d)
        return true;
    else
        return false;
}

int func(vector<pair<long long, long long>> v, vector<int> seq, int m, vector<int> cnt)
{
    if (seq.size() == 1)
        return seq[0] + 1;

    queue<int> lose, win;
    for (int i = 0; i + 1 < seq.size(); i += 2)
    {
        int idx = seq[i], idx2 = seq[i + 1];
        bool res = compare(v[idx].F, v[idx].S, v[idx2].F, v[idx2].S);
        if (!(res))
            swap(idx, idx2);

        win.push(idx);
        cnt[idx2]++;
        if (cnt[idx2] != m)
            lose.push(idx2);
        int tmp = v[idx].F, tmp1 = v[idx].S;
        v[idx].F = v[idx].F + v[idx2].F * v[idx2].S / v[idx].S / 2;
        v[idx].S = v[idx].S + v[idx2].F * v[idx2].S / tmp / 2;
        v[idx2].F = v[idx2].F + v[idx2].F / 2;
        v[idx2].S = v[idx2].S + v[idx2].S / 2;
    }
    if (seq.size() % 2)
        win.push(seq.back());
    seq.clear();
    while (!win.empty())
    {
        seq.pb(win.front());
        win.pop();
    }
    while (!lose.empty())
    {
        seq.pb(lose.front());
        lose.pop();
    }
    return func(v, seq, m, cnt);
}

int main()
{
    loli;
    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].F;
    for (int i = 0; i < n; i++)
        cin >> v[i].S;
    vector<int> seq(n);
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        seq[i] = tmp - 1;
    }

    vector<int> cnt(n, 0);
    print(func(v, seq, m, cnt));
}