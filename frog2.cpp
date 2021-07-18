#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <stack>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <sstream>
#include <iomanip>
using namespace std;

int solve(int i, vector<int> cost, vector<int> &dp, int k)
{
    if (i == 0)
        return 0;

    if (dp[i] != INT_MAX)
        return dp[i];

    for (int j = 1 ; j <= k ; j++)
    {
        if (i - j >= 0)
            dp[i] = min(dp[i], abs(cost[i] - cost[i - j]) + solve(i - j, cost, dp, k));
    }
    return dp[i];
}

int32_t main()
{
    int n = 5;
    // cin >> n;
    int k = 3;

    vector<int> cost = {10, 30, 40, 50, 20};
    // for (int i = 0; i < n; i++)
    //     cin >> cost[i];
    vector<int> dp(100, INT_MAX);

    dp[0] = 0;
    cout << solve(n - 1, cost, dp, k) << endl;
}