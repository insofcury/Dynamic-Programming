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
    int n = 19;
    vector<int> dp(100, INT_MAX-100);
    vector<int> coins = {7, 10};

    //The base condition would have if the total amount left is 0 for which we would need 0 number of coins
    dp[0] = 0;

    //Checking for minimum number of coins when we consider all the coins one by one and including the coin if the total - currency  >= 0 and than chosing the
    //minimum number of coins after that
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < coins.size() ; j++){
            if(i-coins[j] >= 0)
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        }
    }
    //The below code provide as a check to see if we can actually calculate the value by using the types of currency we are provided
    //We do that by checking against the condition of how many coins will be required if the currency would have been 1, in that case the maximum answer can be the total
    //itself and if it is not than that means that it is not possible at all
    
    if(dp[n] > n)
        cout<<-1<<endl;
    else
        cout<<dp[n]<<endl;

}