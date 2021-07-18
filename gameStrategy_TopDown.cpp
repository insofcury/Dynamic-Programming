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
vector<vector<int> >dp(20, vector<int>(20, 0));
// vector<int> arr = {2, 4, 12, 6};
vector<int> arr = {1, 1, 1};

int solve(int i, int j){
    if(i > j)
        return 0;

    if(dp[i][j] != 0)
        return dp[i][j];

    if(i == j-1){
        return dp[i][j] = arr[i] > arr[j] ? arr[i] : arr[j];
    }

    return dp[i][j] = max(arr[i] + min(solve(i+2, j), solve(i+1, j-1)), arr[j] + min(solve(i, j-2), solve(i+1, j-1)));
}


int32_t main()
{
    int first = solve(0, arr.size()-1);
    int second = accumulate(arr.begin(), arr.end(), 0) - first;

    cout<<first<<" "<<second<<endl;

    if(first > second)
        cout<<"FIRST player wins"<<endl;
    else    
        cout<<"SECOND player wins"<<endl;
}