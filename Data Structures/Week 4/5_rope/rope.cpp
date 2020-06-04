// Author:Aryan Yadav

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int t;
	cin >> t;
	while (t--)
	{
		int i, j, k;
		cin >> i >> j >> k;
		int len = j - i;
		len++;
		string s2 = s.substr(i, len);
		s.erase(i, len);
		s.insert(k, s2);
	}
	cout << s;
}
