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
    vector<int> cost = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = cost.size();

    vector<int> dp(n+1, 0);
    
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < i ; j++){
            dp[i] = max(dp[i], cost[j] + dp[i-j-1]);
        }
    }

    for(int x : dp)
        cout<<x<<" ";
    cout<<endl;
    cout<<dp[n]<<endl;
}