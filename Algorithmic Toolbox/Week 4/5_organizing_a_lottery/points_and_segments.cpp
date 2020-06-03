/*
  Author: Aryan Yadav
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++)
  {
    int k;
    cin >> k;
    int ans = 0;
    for (auto i : v)
    {
      if (i.first <= k && i.second >= k)
      {
        ans++;
      }
      if (i.first > k)
      {
        break;
      }
    }
    cout << ans << " ";
  }
}
