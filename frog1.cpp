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

int solve(int i, vector<int> cost, vector<int> &dp)
{
    if (i == 0)
        return 0;

    if (dp[i] != INT_MAX)
        return dp[i];

    dp[i] = min(dp[i], abs(cost[i] - cost[i - 1]) + solve(i - 1, cost, dp));
    if (i - 2 >= 0)
        dp[i] = min(dp[i], abs(cost[i] - cost[i - 2]) + solve(i - 2, cost, dp));

    return dp[i];
}

int32_t main()
{
    int n;
    cin >> n;

    vector<int> cost(n);
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    vector<int> dp(100, INT_MAX);

    dp[0] = 0;
    cout << solve(n - 1, cost, dp) << endl;
}