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
int n;
vector<ll> dp;
void dynamicProgramming () {
    dp.assign(1e5 + 5, 0);
    int temp;
    FOR (i, 1, 1e5) {
        dp[i] = i;
        FOR (j, 1, sqrt(i))
            dp[i] = min (dp[i], dp[i - j*j] + 1);
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
    dynamicProgramming();
    tester()    test();
    return 0;
}