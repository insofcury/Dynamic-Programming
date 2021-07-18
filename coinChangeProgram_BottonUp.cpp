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
    vector<int> dp(100, -1);
    vector<int> coin{1, 7, 10};
    int n = 17;

    dp[0] = 0;
    // dp[1] = 1, dp[7] = 1, dp[10] = 1;

    for(int i = 1 ; i <= n ; i++){
        int temp = INT_MAX;
        for(int j = 0 ; j < coin.size() ; j++){
            if(i-coin[j] >= 0)
                temp = min(temp, dp[i-coin[j]]);
        }
        dp[i] = temp + 1;
    }
    cout<<dp[n]<<endl;
}