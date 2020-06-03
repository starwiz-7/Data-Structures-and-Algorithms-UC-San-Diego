/*
  Author: Aryan Yadav
*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
  double r1 = (double)p1.first / p1.second;
  double r2 = (double)p2.first / p2.second;
  return r1 > r2;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  // double value = 0.0;
  int n = weights.size();
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++)
  {
    v.push_back(make_pair(values[i], weights[i]));
  }
  sort(v.begin(), v.end(), cmp);
  // write your code here
  int curw = 0;
  double val = 0.0;
  for (int i = 0; i < n; i++)
  {
    if (curw + v[i].second <= capacity)
    {
      curw += v[i].second;
      val += v[i].first;
    }
    else
    {
      int rem = capacity - curw;
      val += v[i].first * ((double)rem / v[i].second);
      break;
    }
  }
  return val;
}

int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
