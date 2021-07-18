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
vector<vector<int> > cost = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
vector<int> dp(4, INT_MIN);
int n = 3;

int solve(int i, int flag)
{
    if (i == n-1)
        return 0;

    if (dp[i] != INT_MIN)
        return dp[i];

    for (int j = 0; j < 3; j++)
    {
        if (flag != i)
            dp[i] = max(dp[i], cost[i][j] + solve(i + 1, ));
    }
    return dp[n];
}

int32_t main()
{
    // int n = 3;
    int i = 0;
    int temp = INT_MIN;

    temp =  max(temp, cost[0][0] + solve(i+1, 0));
    cout<<temp<<" ";
    temp = max(temp, cost[0][1] +solve(i+1, 1));
    cout<<temp<<" ";
    
    temp = max(temp, cost[0][2] +solve(i+1, 2));
    cout<<temp<<" ";

    cout <<endl <<temp << endl;

    cout<<endl<<endl;
    for(int x : dp)
        cout<<x<<" ";
}