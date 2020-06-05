// Author: Aryan Yadav

#include <bits/stdc++.h>

using namespace std;
void printKMax(int v[], int n, int k)
{
    std::deque<int> q(k);
    int i;
    for (i = 0; i < k; ++i)
    {
        while ((!q.empty()) && v[i] >= v[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    for (; i < n; ++i)
    {
        cout << v[q.front()] << " ";
        while ((!q.empty()) && q.front() <= i - k)
            q.pop_front();
        while ((!q.empty()) && v[i] >= v[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    cout << v[q.front()];
}
int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;
    printKMax(v, n, k);
    return 0;
}
