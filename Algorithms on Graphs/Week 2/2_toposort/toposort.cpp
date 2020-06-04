// Author: Aryan Yadav

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005] = {false};
stack<int> s;
void topo_sort(int i)
{
  visited[i] = true;
  for (auto u : adj[i])
  {
    if (visited[u] == false)
    {
      topo_sort(u);
    }
  }
  s.push(i);
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

  for (int i = 1; i <= n; i++)
  {
    if (visited[i] == false)
    {
      topo_sort(i);
    }
  }

  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
}
