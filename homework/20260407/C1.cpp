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

int n;
vector<vector<int>> v; // 存積木堆疊
vector<int> pos;       // 快速尋找積木目前在哪一堆

// 輔助函式：將積木 x 上方的所有積木歸位
void clear_above(int x)
{
    int p = pos[x];
    while (v[p].back() != x)
    {
        int top = v[p].back();
        v[top].push_back(top); // 回到初始位置 (位置編號等於積木編號)
        pos[top] = top;        // 更新位置紀錄
        v[p].pop_back();       // 從舊堆移走
    }
}

// 輔助函式：將積木 a 及其上方的積木整疊搬到積木 b 所在的堆
void pile_to(int a, int b)
{
    int pa = pos[a];
    int pb = pos[b];
    vector<int> temp;

    // 找出 a 在 pa 堆中的位置並提取 a 以上的所有積木
    // 因為要保持順序，我們先存入 temp 陣列
    auto it = find(v[pa].begin(), v[pa].end(), a);
    for (auto i = it; i != v[pa].end(); ++i)
    {
        temp.push_back(*i);
        pos[*i] = pb; // 搬運時同步更新位置紀錄
    }

    // 從原堆中刪除 a 及其以上的部分
    v[pa].erase(it, v[pa].end());

    // 將整疊積木壓入目標堆 pb
    for (int x : temp)
    {
        v[pb].push_back(x);
    }
}

int main()
{
    loli;

    if (!(cin >> n))
        return 0;

    v.resize(n);
    pos.resize(n);
    for (int i = 0; i < n; i++)
    {
        v[i].push_back(i);
        pos[i] = i;
    }

    string s1, s2;
    int a, b;
    while (cin >> s1 && s1 != "quit")
    {
        cin >> a >> s2 >> b;

        // 非法指令判斷：a == b 或 a, b 在同一疊
        if (a == b || pos[a] == pos[b])
            continue;

        // 根據指令組合決定是否要歸位
        if (s1 == "move")
            clear_above(a);
        if (s2 == "onto")
            clear_above(b);

        // 最後統一執行搬運 (move 一個或 pile 一疊)
        pile_to(a, b);
    }

    // 輸出最後結果
    for (int i = 0; i < n; i++)
    {
        cout << i << ":";
        for (int x : v[i])
        {
            cout << " " << x;
        }
        cout << "\n";
    }

    return 0;
}