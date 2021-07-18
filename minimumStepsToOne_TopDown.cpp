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
//Minimum steps to reach step one starting from n where we can take following steps -
// (1) n/2 (2) n/3 (3) n-1

vector<int> dp(100, INT_MAX);

int solve(int x)
{
    //The base condition accounts for all those situtions where the user has reached step 1 or any invalid(negative) inputs where it would return 0
    if (x <= 1)
        return 0;

    //We are memoizing here so as to avoid recursive calls if we have already calculated the value previously
    if (dp[x] != INT_MAX)
        return dp[x];

    //Here we check for divisibility of step with 3 and 2 and if it is divisibile we reduce the step count and recursively call the function with adding 1
    //for the step counted and storing the minimum on every step
    if (x % 3 == 0)
        dp[x] = min(dp[x], solve(x / 3) + 1);
    if ((x & 1) == 0)
        dp[x] = min(dp[x], solve(x / 2) + 1);

    //Here we are trying to reduce the number of recurise calls by only taking step n-1 iff the number is was not divisible by 2 and 3 as in all the rest of scenarios
    //we will hav step count reduced by n/2 or n/3 which would definetly be less than n-1;
    if (x % 3 != 0 || (x & 1) == 1)
        dp[x] = min(dp[x], solve(x - 1) + 1);

    return dp[x];
}

int32_t main()
{
    int n = 10;
    cout << solve(n)<<endl;
}