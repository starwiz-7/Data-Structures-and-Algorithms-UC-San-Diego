// Author: Aryan Yadav

// #include <iostream>
// #include <vector>

// using std::vector;
// using std::pair;

// int reach(vector<vector<int> > &adj, int x, int y) {
//   //write your code here
//   return 0;
// }

// int main() {
//   size_t n, m;
//   std::cin >> n >> m;
//   vector<vector<int> > adj(n, vector<int>());
//   for (size_t i = 0; i < m; i++) {
//     int x, y;
//     std::cin >> x >> y;
//     adj[x - 1].push_back(y - 1);
//     adj[y - 1].push_back(x - 1);
//   }
//   int x, y;
//   std::cin >> x >> y;
//   std::cout << reach(adj, x - 1, y - 1);
// }
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
  int ctr = 0;
  for (int i = 1; i <= n; i++)
  {
    if (visited[i] == true)
      continue;
    dfs(i);
    ctr++;
  }
  cout << ctr;
}
