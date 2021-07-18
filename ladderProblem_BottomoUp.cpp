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
    int n = 6;
    int k = 3;

    vector<int> dp(n + 1, 0);
    dp[0] = 1, dp[1] = 1;


    //using sliding window concept we are just have the calculated output of k window which decreases the time complexity to (n) as now we can calculate the number of ways 
    //by excluding the last window in the sequence and adding the next window
    for (int i = 2; i <= n; i++)
    {
        if(i-k <= 0)
            dp[i] = 2*dp[i-1];
        else
            dp[i] = 2*dp[i-1] - dp[i-k-1];
    }

    for(int x : dp)
        cout<<x<<" ";
    cout<<endl;
    cout << dp[n] << endl;
}