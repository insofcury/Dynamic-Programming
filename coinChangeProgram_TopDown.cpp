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
vector<int> dp(100, -1);
vector<int> coin{1, 7, 10};

int solve(int n)
{
    if (dp[n] != -1)
        return dp[n];

    int temp = solve(n - coin[0]);

    for(int i = 1 ; i < coin.size() ; i++){
        if (n - coin[i] >= 0)
            temp = min(temp, solve(n - coin[i]));
    
    }
    return dp[n] = temp + 1;
}

int32_t main()
{
    int n = 15;
    dp[0] = 0, dp[1] = 1, dp[7] = 1, dp[10] = 1;

    cout << solve(n) << endl;
}