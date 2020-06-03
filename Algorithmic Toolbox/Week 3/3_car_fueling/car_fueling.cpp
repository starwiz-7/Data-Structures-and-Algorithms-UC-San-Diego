/*
  Author: Aryan Yadav
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    // write your code here
    int ans = 0;
    if (tank < stops[0])
        return -1;
    int t = tank;
    for (int i = 0; i < stops.size() - 1; i++)
    {
        if (i == 0)
            t -= stops[i];

        else
            t -= stops[i] - stops[i - 1];
        if (t >= (stops[i + 1] - stops[i]))
            continue;
        else
        {
            t = tank;
            if (t < (stops[i + 1] - stops[i]))
                return -1;
            else
            {
                ans++;
            }
            // cout << ans << " ";
        }
    }
    t -= stops[stops.size() - 1] - stops[stops.size() - 2];
    int dd = dist - stops[stops.size() - 1];
    if (t < dd)
    {
        t = tank;
        if (t < dd)
            return -1;
        else
            ans++;
    }
    return ans;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
