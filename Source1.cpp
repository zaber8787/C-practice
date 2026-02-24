#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n = 1;
	for (int i = 0; i < 10; i++)
	{
		n *= 340;
	}
	string ans = "";
	while (n > 2)
	{
		if (n % 2 == 1)
		{
			ans = "1" + ans;
			n -= 1;
		}
		else
		{
			ans = "0" + ans;
		}
		n /= 2;
	}
	cout << ans << endl;
}