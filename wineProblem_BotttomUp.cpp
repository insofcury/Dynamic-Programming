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
    vector<int> wine = {2, 3, 5, 1, 4};
    vector<vector<int> > dp(wine.size(), vector<int>(wine.size(), 0));
    int n = wine.size();

    //considering the case when the last bottle is remaining in that case the total price will became the price of the wine multiplied by the total number of wines
    for (int i = 0; i < n; i++)
    {
            dp[i][i] = wine[i] * n;
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            //price of wine when the left wine bottle is chosen
            dp[i][j] = max(dp[i][j], (n - j + i) * wine[i] + dp[i + 1][j]);
            //price of wine when the right bottle is chosen
            dp[i][j] = max(dp[i][j], (n - j + i) * wine[j] + dp[i][j - 1]);
            //maximum of both of them will give us maximum price of wine possible while picking wine from only left and right end
        }
    }

    cout << dp[0][n - 1] << endl;
}