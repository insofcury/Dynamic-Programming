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

int32_t main()
{
    vector<int> wines{2, 3, 5, 1, 4};
    vector<vector<int> > dp(100, vector<int>(100, 0));
    // int dp[wines.size()][wines.size()];

    dp[0][0] = wines[0] * wines.size();

    for (int j = 1; j <= wines.size()-1; j++)
    {
        for (int i = j; i >= 0; i--)
        {
            int m = wines.size() - (j - i);
            dp[i][j] = max(m * wines[j] + dp[i][j-1], m * wines[i] + dp[i+1][j]);
        }
    }
    cout << dp[0][wines.size() - 1] << endl;
}