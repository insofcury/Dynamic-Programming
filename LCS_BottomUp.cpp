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
    string s = "BABCD";
    string t = "ABEDG";
    string result = "";
    vector<vector<int> > dp(6, vector<int>(6, 0));

    for(int i = s.size()-1 ; i >= 0 ; i--){
        for(int j = t.size()-1 ; j >= 0 ; j--){
            //Considering the case where the characters are equal we will call the next character in line
            if(s[i] == t[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else
                //considering the case where the characters are not equal in that case we will skip the character one by one and find the maximum length in both the cases
                dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    cout<<dp[0][0]<<endl;
    cout<<result<<endl;
}