// Author: Aryan Yadav

#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::cin;
using std::cout;
using std::ios_base;
using std::vector;

class TreeOrders
{
  int n;
  vector<int> key;
  vector<int> left;
  vector<int> right;
  vector<int> result;

public:
  void read()
  {
    cin >> n;
    if (n == 0)
    {
      return;
    }
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++)
    {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  vector<int> in_order()
  {
    result.clear();
    if (n == 0)
    {
      final();
    }
    else
    {
      inorder(0);
    }
    return result;
  }

  void inorder(int i)
  {
    if (left[i] != -1)
      inorder(left[i]);
    result.push_back(key[i]);
    if (right[i] != -1)
      inorder(right[i]);
  }

  bool final()
  {
    if (n == 0)
    {
      return true;
    }
    vector<int> f = result;
    sort(f.begin(), f.end());
    for (int i = 0; i < f.size(); i++)
    {
      if (f[i] != result[i])
        return false;
    }
    return true;
  }
};

int main_with_large_stack_space()
{
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  t.in_order();
  bool k = t.final();
  if (k == true)
  {
    cout << "CORRECT";
  }
  else
  {
    cout << "INCORRECT";
  }
  return 0;
}

int main(int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024; // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        std::cerr << "setrlimit returned result = " << result << std::endl;
      }
    }
  }
#endif

  return main_with_large_stack_space();
}
