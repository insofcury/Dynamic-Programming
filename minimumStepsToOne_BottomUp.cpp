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
    int n = 10;
    vector<int> dp(100, INT_MAX);
    dp[0] = 0, dp[1] = 0;

    for(int i = 2 ; i <= n ; i++){

        //Here we check for divisibility of step with 3 and 2 and if it is divisibile we reduce the step count and recursively call the function with adding 1
        //for the step counted and storing the minimum on every step 
        if(i%3 == 0)
            dp[i] = min(dp[i], dp[i/3] + 1);
        if((i&1) == 0)
            dp[i] = min(dp[i], dp[i/2] + 1);
            
        //Here we are trying to reduce the number of recurise calls by only taking step n-1 iff the number is was not divisible by 2 and 3 as in all the rest of scenarios
        //we will hav step count reduced by n/2 or n/3 which would definetly be less than n-1;
        if(i%3 != 0 || (i&2) == 1)
            dp[i] = min(dp[i], dp[i-1] + 1);
    }
    cout<<dp[n]<<endl;

}