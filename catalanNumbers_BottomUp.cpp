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
    int n = 6;
    vector<int> dp(100, 0);
    
    dp[0] = 1, dp[1] = 1;
    
    for(int i = 2 ; i <= n ; i++){
        for(int j = 0 ; j < i ; j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }

    cout<<dp[n]<<endl;
}