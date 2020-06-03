/*
  Author: Aryan Yadav
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;

long long max_dot_product(vector<int> a, vector<int> b)
{
  // write your code here
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  long long result = 0;
  long long r1 = 0;
  for (size_t i = 0; i < a.size(); i++)
  {
    result += ((long long)a[i]) * b[i];
    if (result >= r1)
    {
      r1 = result;
    }
    if (result < r1)
    {
      break;
    }
  }
  result = r1;
  return result;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
