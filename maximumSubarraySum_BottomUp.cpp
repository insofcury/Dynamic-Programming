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

//Space optimization by using a single array when compared with the whole array as we just need to store the sum
// int32_t main()
// {
//     vector<int> arr = {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
//     int sum = arr[0] > 0 ? arr[0] : 0;
//     int maxSum = sum;

//     for (int i = 1; i < arr.size(); i++)
//     {
//         sum = sum + arr[i];

//         //need to check if the added value makes the sum negative in that case we need to ignore that value and store 0 instead
//         if (sum < 0)
//             sum = 0;

//         //After every step we evaluate the maximum sum
//         maxSum = max(sum, maxSum);
//     }

//     //In case the array only contain negative values return the maximum number out of the array and that will be our answer
//     if (maxSum == 0)
//         cout << *max_element(arr.begin(), arr.end()) << endl;

//     cout << maxSum << endl;
// }

int32_t main()
{
    vector<int> arr {-3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
    vector<int> dp(arr.size(), 0);
    int val = INT_MIN;

    dp[0] = arr[0] > 0 ? arr[0] : 0;

    for(int i = 1 ; i < arr.size(); i++){
        dp[i] = dp[i-1] + arr[i];

        //need to check if the added value makes the sum negative in that case we need to ignore that value and store 0 instead
        if(dp[i] < 0)
            dp[i] = 0;

        //After every step we evaluate the maximum sum
        val = max(val, dp[i]);
    }

    //In order to print the array we can find the index which is giving maxSum in dp and traverse backwards to find the index where dp sum becomes 0
    //from that position onwards all the elements are contributing to the max subarray sum
    
    int index = find(dp.begin(), dp.end(), val) - dp.begin();
    int l;
    for(l = index ; l >= 0 ; l--){
        if(dp[l] == 0)
            break;
    }
    vector<int> array;
    for(int i = l+1 ; i <= index ; i++){
        array.push_back(arr[i]);
    }

    for(int x : array)
        cout<<x<<" ";
    
    cout<<endl;


    //In case the array only contain negative values return the maximum number out of the array and that will be our answer
    if(val == 0)
        cout<<*max_element(arr.begin(), arr.end())<<endl;

    cout<<val<<endl;

}