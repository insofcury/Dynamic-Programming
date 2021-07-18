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

vector<vector<int> >dp(100, vector<int>(100, 0));
vector<int> v = {2, 4, 7, 6};

int solve(int i, int j){
    if(i >= j)
        return 0;
    
    // if(i = j-1)
    //     return v[i];
    

    if(dp[i][j] != 0)
        return dp[i][j];

    return dp[i][j] = max(v[i] + min(solve(i+2, j), solve(i+1, j-1)), v[j] + min(solve(i+1, j-1), solve(i, j-2)));
}

int32_t main()
{

    cout<<solve(0, v.size()-1)<<endl;


}