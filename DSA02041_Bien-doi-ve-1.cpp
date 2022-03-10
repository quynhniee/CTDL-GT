#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<int> dp;
int n;
void init () {
    dp.assign(100005, 0);   // số cách tối thiểu biến đổi i về 1
    dp[3] = dp[2] = 1;  
    FOR (i, 4, 100000) {
        if (i % 6 == 0) 
            dp[i] = min(dp[i-1], min(dp[i/2], dp[i/3])) + 1;
        else if (i % 3 == 0)
            dp[i] = min(dp[i-1], dp[i/3]) + 1;
        else if (i % 2 == 0)
            dp[i] = min(dp[i-1], dp[i/2]) + 1;
        else dp[i] = dp[i-1] + 1;
    }
}
void test () {
    cin >> n;
    cout << dp[n] << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    tester()    test();
    return 0;
}