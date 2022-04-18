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
vector<ll> dp;
int n, k;
void solution () {
    cin >> n >> k;
    dp.assign(1, 1);
    ll s = 0;
    int m = min (n, k);
    FOR (i, 1, m) {
        s += dp[i-1];
        dp.push_back(s%mod);
    }
    FOR (i, m+1, n) {
        s = s - dp[i-1-m] + dp[i-1];
        dp.push_back(s%mod);
    }
    cout << dp[n] << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
    solution();
    return 0;
}