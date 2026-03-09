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
// https://vjudge.net/problem/UVA-10221

int main()
{
    double s, a;
    string unit;
    const double PI = acos(-1.0);
    const double r = 6440.0;

    while (cin >> s >> a >> unit)
    {
        // 1. 單位轉換
        if (unit == "min")
            a /= 60.0;

        // 2. 角度修正 (取短弧)
        if (a > 180.0)
            a = 360.0 - a;

        double R = r + s;
        double rad = a * PI / 180.0;

        // 3. 計算
        double arc = R * rad;                    // 弧長 S = R * theta (弧度)
        double chord = 2.0 * R * sin(rad / 2.0); // 弦長

        cout << fixed << setprecision(6) << arc << " " << chord << endl;
    }
    return 0;
}