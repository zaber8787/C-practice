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

void handle_plural(string &word)
{
    string if_es[4] = {"o", "s", "x", "z"};
    string vowel[5] = {"a", "e", "i", "o", "u"};

    if (word[word.size() - 1] == 'y' && find(begin(vowel), end(vowel), string(1, word[word.size() - 2])) == end(vowel))
    {
        word.pop_back();
        word += "ies";
        cout << word << "\n";
        return;
    }

    string last_two = word.substr(word.size() - 2, 2);
    if (last_two == "ch" || last_two == "sh" || find(begin(if_es), end(if_es), string(1, word[word.size() - 1])) != end(if_es))
    {
        word += "es";
        cout << word << "\n";
        return;
    }
    else
    {
        word += "s";
        cout << word << "\n";
        return;
    }
}

int main()
{
    loli int l, n;
    cin >> l >> n;
    map<string, string> special;
    for (int i = 0; i < l; i++)
    {
        string a, b;
        cin >> a >> b;
        special[a] = b;
    }
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        if (special.count(word))
            cout << special[word] << "\n";
        else
            handle_plural(word);
    }
}