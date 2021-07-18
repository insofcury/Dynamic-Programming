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

vector<int> w = {6, 5, 6, 6, 3, 7};
vector<int> cost = {5, 6, 4, 6, 5, 2};

vector<vector<int> > dp(100, vector<int>(100, 0));

int solve(int n, int t)
{
    if (n < 0)
        return 0;

    if (dp[n][t] != 0)
        return dp[n][t];

    if (w[n] > t)
    {
        return dp[n][t] = solve(n - 1, t);
    }
    else
    {
        return dp[n][t] = max(solve(n - 1, t), cost[n] + solve(n - 1, t - w[n]));
    }
    return dp[n][t];
}

int32_t main()
{
    int t = 15;
    cout << solve(cost.size() - 1, t) << endl;

    
}