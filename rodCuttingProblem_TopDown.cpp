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

vector<int> dp(9, 0);
vector<int> cost = {1, 5, 8, 9, 10, 17, 17, 20};

int solve(int n)
{
    if (n == 0)
        return 0;

    if (dp[n] != 0)
        return dp[n];

    for (int i = 0; i < n; i++)
    {
        dp[n] = max(dp[n], solve(n - i - 1) + cost[i]);
    }
    return dp[n];
}

int32_t main()
{
    int n = 8;

    
    cout<<endl;
    cout << solve(n) << endl;
    for(int x : dp)
        cout<<x<<" ";
}