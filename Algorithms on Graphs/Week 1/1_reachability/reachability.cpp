// Author: Aryan Yadav

#include <bits/stdc++.h>
using namespace std;
vector<int> v[10001];
bool visited[10001] = {false};
void dfs(int i)
{
  if (visited[i])
    return;
  visited[i] = true;
  for (auto u : v[i])
  {
    dfs(u);
  }
  return;
}
int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int l, k;
    cin >> l >> k;
    v[l].push_back(k);
    v[k].push_back(l);
  }
  int a, b;
  cin >> a >> b;
  dfs(a);
  if (visited[b] == true)
  {
    cout << "1";
  }
  else
  {
    cout << "0";
  }
}
