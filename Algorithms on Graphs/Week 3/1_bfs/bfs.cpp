//Author: Aryan Yadav

#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> v[100005];
queue<ll> q;

int main()
{
  ll n, m;
  cin >> n >> m;
  ll distance[100005];
  for (int i = 0; i <= n; i++)
  {
    distance[i] = -1;
  }
  for (ll i = 0; i < m; i++)
  {
    ll a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  ll st, end;
  cin >> st >> end;
  q.push(st);
  distance[st] = 0;
  while (!q.empty())
  {
    ll u = q.front();
    q.pop();
    for (auto i : v[u])
    {
      if (distance[i] == -1)
      {
        q.push(i);
        distance[i] = distance[u] + 1;
      }
    }
  }
  cout << distance[end];
}
