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
vector<ll> a, dp;
void input () {
    cin >> n;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
    dp.assign(n, 0);
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
}
void solve () {
    FOR (i, 2, n-1) {
        dp[i] = max (dp[i-2] + a[i], dp[i-1]);
    }
    cout << dp[n-1] << endl;
}
void test () {
    input ();
    solve ();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}