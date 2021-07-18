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

vector<int> wine = {2, 3, 5, 1, 4};
vector<vector<int> >dp(wine.size(), vector<int>(wine.size(), 0));

int solve(int i, int j, int y){
    //Filling the array for conditions where only one bottle is left in that case the year passed would be equal to the size of the wine array
    if(i == j)
        return wine[i]*wine.size();
    if(i > j)
        return 0;


    if(dp[i][j] != 0)
        return dp[i][j];

    dp[i][j] = 0;
    dp[i][j] = max(dp[i][j], y*wine[i] + solve(i+1, j, y+1));
    dp[i][j] = max(dp[i][j], y*wine[j] + solve(i, j-1, y+1));

    return dp[i][j];
}

int32_t main()
{
    // for(int i = 0 ; i < wine.size() ; i++){
    //     dp[i][i] = wine[i] * wine.size();
    // }

    cout<<solve(0, wine.size()-1, 1)<<endl;
    for(int i = 0 ; i < wine.size() ; i++){
        for(int j = 0 ; j < wine.size() ; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

}