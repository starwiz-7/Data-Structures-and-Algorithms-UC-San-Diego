// Author: Aryan Yadav

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005] = {false};
bool rec[1005] = {false};

bool iscyclic(int i)
{
  if (visited[i] == false)
  {
    visited[i] = true;
    rec[i] = true;

    for (auto u : adj[i])
    {
      if (!visited[u] && iscyclic(u))
      {
        return true;
      }
      else if (rec[u])
      {
        return true;
      }
    }
  }
  rec[i] = false;
  return false;
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
  }
  bool cyclic = false;
  for (int i = 1; i <= n; i++)
  {
    if (iscyclic(i))
    {
      cyclic = true;
      break;
    }
  }
  if (cyclic == true)
  {
    cout << 1;
  }
  else
  {
    cout << 0;
  }
}
