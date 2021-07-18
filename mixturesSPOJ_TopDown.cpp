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
vector<int> m = {40, 60, 20};
vector<vector<int> >dp(3, vector<int>(3, -1));

int sum(int x, int y){
    int temp  = 0;
    int i = x;
    while(i <= y){
        temp += m[i];
        temp %= 100;
        i++;
    }
    return temp;
}

int calculateSmoke(int i, int j){
    if(i >= j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;
    for(int k = i ; k <= j ; k++){
        dp[i][j] = min(dp[i][j], calculateSmoke(i, k) + calculateSmoke(k+1, j) + sum(i, k) * sum(k+1, j));
    }
    return dp[i][j];
}

int32_t main()
{
    cout<<calculateSmoke(0, 2)<<endl;

}