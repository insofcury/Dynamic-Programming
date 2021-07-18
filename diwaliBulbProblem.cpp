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

int dp[ 100 ][ 2 ][ 100 ];
int n = 10, x = 9; 


//all we need is to store the previous bit bcoz that would detemine if the product 
int solve(int idx, int bit, int count){
    if(idx == n){
        if(count == x)
            return 1;
        else    
            return 0;
    }

    if(dp[idx][bit][count] != -1)
        return dp[idx][bit][count];

    int res = 0;

    //if are taking care of situation in case the current bit is 0 or 1 in case of 0
    //things will be same for any prev bit but in case of 1 we have to consider two situations
    if(bit == 1){
        res += solve(idx+1, 1, count+1);
    }
    else{
        res += solve(idx+1, 1, count);
    }
    res += solve(idx+1, 0, count);
    return dp[idx][bit][count] = res;
}


int32_t main()
{
    memset(dp, -1, sizeof(dp));
    cout<<solve(1, 0, 0) + solve(1, 1, 0)<<endl;

}