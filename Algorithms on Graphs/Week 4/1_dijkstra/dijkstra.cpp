//Author: Aryan Yadav

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ip;
vector<ip> v[10005];

void sht(int src, int end)
{
  priority_queue<ip, vector<ip>, greater<ip>> p;
  vector<int> dist(10005, INT_MAX);
  p.push(make_pair(0, src));
  dist[src] = 0;

  while (!p.empty())
  {
    int u = p.top().second;
    p.pop();
    for (auto x : v[u])
    {
      int q = x.first;
      int wt = x.second;
      if (dist[q] > dist[u] + wt)
      {
        dist[q] = dist[u] + wt;
        p.push(make_pair(dist[q], q));
      }
    }
  }
  if (dist[end] == INT_MAX)
  {
    cout << -1;
  }
  else
  {
    cout << dist[end];
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back(make_pair(b, c));
  }
  int u, v;
  cin >> u >> v;

  sht(u, v);
}
