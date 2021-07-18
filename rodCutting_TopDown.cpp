#include <limits.h>
#include <queue>
#include <set>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;
vector<int> dp(100, INT_MIN);

int rodcutting(int n, vector<int> &prices)
{
    if (n <= 0)
        return 0;
    int max_profit = INT_MIN;
    if(dp[n] != INT_MIN)
        return dp[n];
    for (int i = 0; i < n; i++)
    {
        int curr = prices[i] + rodcutting(n - i - 1, prices);
        max_profit = max(max_profit, curr);
    }
    return dp[n] = max_profit;
}

int main()
{
    dp[0] = 0;
    vector<int> prices{1, 5, 8, 9, 10, 17, 17, 20};
    cout << rodcutting(prices.size(), prices)<<endl;
    return 0;
}
