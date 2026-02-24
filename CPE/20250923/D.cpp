#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    int n;
    while (cin >> n)
    {
        v.pb(n);
        sort(v.begin(), v.end());
        if (v.size() % 2 == 1)
            cout << v[v.size() / 2] << "\n";
        else
            cout << (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2 << "\n";
    }
}