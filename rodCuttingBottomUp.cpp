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
    int rod = 8;
    vector<int> price{1,5,8,9,10,17,17,20};

    vector<int> dp(rod+1, INT_MIN);
    dp[0] = 0;

    for(int i = 1 ; i <= rod ; i++){
        for(int j = 0 ; j < i ; j++){
            dp[i] = max(dp[i], price[j] + dp[i-j-1]);
        }
    }

    cout<<dp[rod]<<endl;

}