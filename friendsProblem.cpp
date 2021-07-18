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

vector<int> dp(100, 0);

int solve(int n){
    if(n<=1)
        return dp[1] = 1;

    if(dp[n] != 0)
        return dp[n];

    return dp[n] = solve(n-1) + (n-1) * solve(n-2);
}

int32_t main()
{
    int n = ;
    cout<<solve(n)<<endl;

}