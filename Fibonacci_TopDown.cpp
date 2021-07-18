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
vector<int> v(11, -1);

int bottomUp(int n){
    if(n == 0 || n == 1){
        return v[n]; 
    }
    if(v[n] != -1)
        return v[n];
    else{
        v[n] = bottomUp(n-1) + bottomUp(n-2);
        return v[n];
    }
}

int32_t main()
{
    v[0] = 0, v[1] = 1;
    int n = 5;
    cout<<bottomUp(n)<<endl;

}