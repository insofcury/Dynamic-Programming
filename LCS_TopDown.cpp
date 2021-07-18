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

vector<vector<int> > dp(8, vector<int>(8, 0));
string result = "";
int solve(string s, string t, int i, int j)
{
    if (i == s.size() || j == t.size())
    {
        return 0;
    }

    if (dp[i][j] != 0)
        return dp[i][j];

    //Considering the case where the characters are equal we will call the next character in line
    if (s[i] == t[j])
    {
        result += s[i];
        dp[i][j] = max(dp[i][j], solve(s, t, i + 1, j + 1) + 1);
    }
    else
    {
        //considering the case where the characters are not equal in that case we will skip the character one by one and find the maximum length in both the cases
        dp[i][j] = max(dp[i][j], solve(s, t, i + 1, j));
        dp[i][j] = max(dp[i][j], solve(s, t, i, j + 1));
    }
    return dp[i][j];
}

int32_t main()
{
    string s = "ABCDXYZ";
    string t = "ABEDG";

    cout << solve(s, t, 0, 0) << endl;
    cout << result << endl;
}