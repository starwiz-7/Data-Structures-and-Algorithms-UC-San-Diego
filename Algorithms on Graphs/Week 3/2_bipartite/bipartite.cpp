// Author: Aryan Yadav

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
queue<int> q;

bool isbip(int color[], int i)
{
  color[i] = 1;
  q.push(i);
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (auto i : adj[u])
    {
      if (i == u)
      {
        return false;
      }
      if (color[i] == -1)
      {
        color[i] = 1 - color[u];
        q.push(i);
      }
      else if (color[i] == color[u])
        return false;
    }
  }
  return true;
}

bool isbipartite(int color[], int n)
{
  for (int i = 1; i <= n; i++)
  {
    if (color[i] == -1)
    {
      if (isbip(color, i) == false)
        return false;
    }
  }
  return true;
}
int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int l, k;
    cin >> l >> k;
    adj[l].push_back(k);
    adj[k].push_back(l);
  }
  int color[100005];
  for (int i = 0; i <= n; i++)
  {
    color[i] = -1;
  }
  isbipartite(color, n) ? cout << 1 : cout << 0;
}
