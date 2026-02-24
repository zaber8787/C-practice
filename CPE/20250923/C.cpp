#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define ll long long

int binary(int n){
    int result = 0, base = 0;
    while(n > 0){
        if (n % 2 == 1)result += pow(10, base);
        n /= 2;
        base++;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    n = binary(n);
    m = binary(m);
    int tmp = n + m;
    int ans = 0;
    int base = 0;
    while (tmp > 0)
    {
        if (tmp % 10 == 1)
            ans += pow(2, base);
        tmp /= 10;
        base++;
    }
    cout << ans;
}