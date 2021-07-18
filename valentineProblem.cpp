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
#include <cmath>
using namespace std;
#define INF 1000000007
vector<vector<int> >dp(6, vector<int>(6, -1));
int n = 3, m = 5;
vector<int> arr1 = {10, 11, 12};
vector<int> arr2 = {1, 2, 3, 6, 8};

int solve(int i, int j){
    //IF we have paired all the boys than we can return 0
    if(i == n)
        return 0;
    //If we have rejected all the girls that means some boys have been left unpaired hence we would need to the reject the case
    if(j == m)
        return INF;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    //Lets say we select the number in that case we will add the diffence
    int a = abs(arr1[i] - arr2[j]) + solve(i+1, j+1);
    //In case we ignore the number we will move the girl array pointer to the next value
    int b = solve(i, j+1);

    return dp[i][j] = min(a, b);
}

int32_t main()
{
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    cout<<solve(0, 0)<<endl;
}