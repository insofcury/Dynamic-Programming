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

double dpR[ 105 ][ 105 ][ 105 ];

double solveR(int r, int s, int p){
    if(r == 0 || s == 0)
        return 0.0;
    if(p == 0)
        return 1.0;
    
    if(dpR[r][s][p] != -1.0)
        return dpR[r][s][p];
    double res = 0.0;    
    res = res + solveR(r-1, s, p) * (r*p)/(r*p + p*s + r*s); 
    res = res + solveR(r, s, p-1) * (p*s)/(r*p + p*s + r*s); 
    res = res + solveR(r, s-1, p) * (r*s)/(r*p + p*s + r*s);
    return dpR[r][s][p] = res;
}

int32_t main()
{

    for(int i = 0 ; i < 100 ; i++){
        for(int j = 0 ; j < 100 ; j++){
            for(int k = 0 ; k < 100 ; k++){
                dpR[i][j][k] = -1.0;
            }
        }
    }

    int rock = 1, paper = 1, scissor = 3;
    // memset(dpR, -1.0, sizeof(dpR));
    cout<<fixed<<setprecision(9)<<solveR(rock, scissor, paper)<<endl;

}