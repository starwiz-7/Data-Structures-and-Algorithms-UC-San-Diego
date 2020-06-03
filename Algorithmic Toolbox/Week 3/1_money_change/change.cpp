/*
  Author: Aryan Yadav
*/

#include <bits/stdc++.h>
using namespace std;
int get_change(int m)
{
  //write your code here
  int n = 0;
  int m1 = m;
  n += m1 / 10;
  m1 = m1 % 10;
  n += m1 / 5;
  m1 = m1 % 5;
  n += m1;
  return n;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
