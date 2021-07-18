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

vector<int> dp(20, 0);

int solve(int n){
    if(n <= 1)
        return 1;
    
    if(dp[n] != 0)
        return dp[n];

    for(int i = 0 ; i < n ; i++){
        dp[n] += (solve(i) * solve(n-i-1));
    }
    return dp[n];
}

int32_t main()
{
    int n = 5;
    cout<<solve(n)<<endl;

}