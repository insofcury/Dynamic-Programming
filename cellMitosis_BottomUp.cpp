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
    int x = 2, y = 1, z = 3;
    int target = 5;

    vector<int> dp(target+1, 0);

    for(int i = 1 ; i <= target ; i++){
        if((i&1) == 1){
            dp[i] = min(dp[i/2] + x, dp[i-1] + y);
        }
        else
            dp[i] = min(dp[i-1] + y, dp[(i+1)/2] + x + z);
    }

    cout<<dp[target]<<endl;

}