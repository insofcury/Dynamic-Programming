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

vector<int> m = {18, 19};
vector<vector<int> >dp(100, vector<int>(100, 0));

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


int32_t main()
{
    int i = 0, j = 2;
    
    for(int j = 1 ; j <= 2 ; j++){
        for(int i = j-1 ; i >= 0 ; i--){
            dp[i][j] = INT_MAX;
            for(int k = i ; k <= j ; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum(i, k) * sum(k+1, j));
            }
        }
    }
    cout<<dp[0][2]<<endl;

}