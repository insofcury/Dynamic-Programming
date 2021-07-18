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

vector<int> dp(5, 0);

int solve(int n, int k)
{
    //the base case would be when we the person would be standing at the starting posiition
    if (n == 0)
        return 1;
    if (dp[n] != 0)
        return dp[n];

    // for(int i = 1; i<=k; i++)
    //     if(n-i >= 0)
    //         dp[n] += solve(n-i, k);

    //To avoid couple of calls here when k is less than n itself we can sum n-1 and the output from recursive calling of fucntion with n-1
    if (n <= k)
        return dp[n] = dp[n] + solve(n - 1, k) + (n-1);

    //recurrence relation here would output of recursive call and the dp itself
    for (int i = 1; i <= k; i++)
    {
        dp[n] = dp[n] + solve(n - i, k);
    }
    return dp[n];
}

int32_t main()
{
    int n = 4;
    int k = 3;
    cout << solve(n, k) << endl;

        for (int x : dp)
            cout << x << " ";
}