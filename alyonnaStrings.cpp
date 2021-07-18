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

string s = "bbaaababb", t = "abbbabbaaaba";
// string s = "abc", t = "ab";
int x = s.size(), y = t.size();

int dp[ 1005 ][ 1005 ][ 12 ][ 2 ];

int solve(int idx_s, int idx_t, int rem, int cont){
    //If we reach the end of any string, we need to check if we have found all the matching substrings
    //else we return INT_MIN
    if(idx_s == x || idx_t == y)
        return (rem == 0 ? 0 : INT_MIN);

    if(rem == 0)
        return 0;

    if(dp[idx_s][idx_t][rem][cont] != -1)
        return dp[idx_s][idx_t][rem][cont];
    
    int res = INT_MIN;

    //optimised code
    // res = max(res, solve(idx_s+1, idx_t, rem-cont, 0));
    // res = max(res, solve(idx_s, idx_t+1, rem-cont, 0));
    // if(s[idx_s] == t[idx_t]){
    //     res = max(res, 1 + solve(idx_s+1, idx_t+1, rem, 1));
    //     res = max(res, 1 + solve(idx_s+1, idx_t+1, rem-1, 0));
    // }

    //Here we are following this idea that untill the current substring has been passed
    //we won't reduce the total number of remaining strings unless we find a non matching character
    if(cont == 1){
        res = max(res, solve(idx_s+1, idx_t, rem-1, 0));
        res = max(res, solve(idx_s, idx_t+1, rem-1, 0));
        if(s[idx_s] == t[idx_t]){
            res = max(res, 1 + solve(idx_s+1, idx_t+1, rem, 1));
            res = max(res, 1 + solve(idx_s+1, idx_t+1, rem-1, 0));
        }
    }
    else{
        res = max(res, solve(idx_s+1, idx_t, rem, 0));
        res = max(res, solve(idx_s, idx_t+1, rem, 0));
        if(s[idx_s] == t[idx_t]){
            res = max(res, 1 + solve(idx_s+1, idx_t+1, rem, 1));
            res = max(res, 1 + solve(idx_s+1, idx_t+1, rem-1, 0));
        }
    }
    return dp[idx_s][idx_t][rem][cont] = res;
}

int32_t main()
{
    int t = 4;
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, 0, t, 0)<<endl;

}