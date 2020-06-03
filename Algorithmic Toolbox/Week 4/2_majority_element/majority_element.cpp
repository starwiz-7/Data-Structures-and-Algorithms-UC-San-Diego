/*
  Author:Aryan Yadav
*/

#include <bits/stdc++.h>
using namespace std;

int get_majority_element(vector<int> &a)
{
  // if (left == right) return -1;
  // if (left + 1 == right) return a[left];
  //write your code here
  unordered_map<int, int> m;
  for (auto i : a)
  {
    m[i]++;
  }
  int n = a.size();
  n /= 2;
  for (auto i : m)
  {
    if (i.second > n)
    {
      return 1;
    }
  }
  return 0;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a)) << '\n';
}
