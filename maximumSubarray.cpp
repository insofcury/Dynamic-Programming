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
    vector<int> arr {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    vector<int> dp(50, INT_MIN);
    dp[0] = arr[0] > 0 ? arr[0] : 0;
    int maxSoFar = dp[0];

    for(int i = 1 ; i < arr.size() ; i++){
        dp[i] = dp[i-1] + arr[i];

        if(dp[i] < 0)
            dp[i] = 0;
        
        if(dp[i] > maxSoFar)
            maxSoFar = dp[i];
    }
    cout<<maxSoFar<<endl;
}