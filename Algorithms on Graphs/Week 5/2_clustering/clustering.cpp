//  Author: Aryan Yadav

#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int start, end;
  double dis;
  Node(int x, int y, double d) : start(x), end(y), dis(d){};
  bool operator<(const Node &a) const { return dis < a.dis; }
};
int Find(int x, vector<int> &parent)
{
  if (x != parent[x])
    parent[x] = Find(parent[x], parent);
  return parent[x];
}
void Union(int x, int y, vector<int> &parent)
{
  int left = Find(x, parent);
  int right = Find(y, parent);
  if (left != right)
  {
    parent[right] = left;
  }
}

double clustering(vector<int> x, vector<int> y, int k)
{
  // write your code here
  int num = 0;
  vector<int> parent(x.size());
  vector<Node> q;
  for (size_t i = 0; i < x.size(); i++)
    parent[i] = i;
  for (size_t i = 0; i < x.size(); i++)
  {
    for (size_t j = i + 1; j < x.size(); j++)
    {
      double dis =
          sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      q.push_back(Node(i, j, dis));
    }
  }
  sort(q.begin(), q.end());

  for (size_t i = 0; i < q.size(); i++)
  {
    Node v = q[i];
    if (Find(v.start, parent) !=
        Find(v.end, parent))
    {
      if (num == x.size() - k)
        return v.dis;
      num++;
      Union(v.start, v.end, parent);
    }
  }
}

int main()
{
  size_t n;
  int k;
  cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i];
  }
  cin >> k;
  cout << setprecision(10) << clustering(x, y, k) << endl;
  return 0;
}
