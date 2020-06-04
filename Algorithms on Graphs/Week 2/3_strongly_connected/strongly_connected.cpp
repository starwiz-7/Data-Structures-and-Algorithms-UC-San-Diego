/*
    Author: Aryan Yadav
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define f(i, a, b) for (long long i = a; i < b; i++)
#define rep(i, a, b) for (long long i = a; i <= b; i++)
#define fm(i, a, b) for (long long i = a; i > b; i--)
#define repm(i, a, b) for (long long i = a; i >= b; i--)
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
#define pqmaxi priority_queue<int>
#define pqmaxl priority_queue<ll>
#define pqmini priority_queue<int, vi, greater<int>>
#define pqminl priority_queue<ll, vl, greater<ll>>
#define all(x) x.begin(), x.end()
#define test   \
  ll test;     \
  cin >> test; \
  while (test--)
#define pb(i) push_back(i)
#define mp(i, j) make_pair(i, j)
#define fast                   \
  ios::sync_with_stdio(false); \
  cin.tie(NULL)

vector<int> adj[10001];
vector<int> rev_adj[10001];
bool visited[10001] = {false};
stack<int> s;
int n;
void fillorder(int i)
{
  visited[i] = true;
  for (auto u : adj[i])
  {
    if (!visited[u])
    {
      fillorder(u);
    }
  }
  s.push(i);
}

void getTranspose()
{
  f(i, 0, n + 1)
  {
    for (auto u : adj[i])
    {
      rev_adj[u].pb(i);
    }
  }
  return;
}
void dfs(int i)
{
  visited[i] = true;
  for (auto u : rev_adj[i])
  {
    if (!visited[u])
      dfs(u);
  }
}
int main()
{
  fast;
  int m;
  cin >> n >> m;
  f(i, 0, m)
  {
    int l, k;
    cin >> l >> k;
    adj[l].pb(k);
  }
  f(i, 1, n + 1)
  {
    if (visited[i] == false)
    {
      fillorder(i);
    }
  }
  getTranspose(); //getting reverse of the given graph
  f(i, 1, n + 1)
  {
    visited[i] = false; //For second DFS
  }
  int cnt = 0;
  while (!s.empty())
  {
    int v = s.top();
    s.pop();
    if (visited[v] == false)
    {
      dfs(v);
      cnt++;
    }
  }
  cout << cnt;
}
