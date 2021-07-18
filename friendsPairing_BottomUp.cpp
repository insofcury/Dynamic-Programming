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
    int n = 4;
    vector<int> dp(5, 0);

    for(int i = 0 ; i <= 4 ; i++){
        if(i <= 2)
            dp[i] = i;
        else{
            dp[i] = dp[i-1] + dp[i-2] * (i-1);
        }
    }
    cout<<dp[n]<<endl;

}