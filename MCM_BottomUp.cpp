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
    vector<int> cost = {4, 2, 3, 1, 3};
    int n = cost.size()-1;
    vector<vector<int> > dp(n, vector<int>(n, 0));

    //Since the multiplication of a matrix with itself wont cost anything that serves as the base case of our problem
    
    for(int j = 1 ; j < n ; j++){
        for(int i = j-1 ; i >= 0 ; i--){
            dp[i][j] = INT_MAX;
            
            //here we are taking a pivot at a time and finding cost on both the side and storing the minimum cost calculated while taking all the pivots
            for(int k = i ; k < j ; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost[i]*cost[k+1]*cost[j+1]);
            }
        }
    }

    cout<<dp[0][n-1]<<endl;
}