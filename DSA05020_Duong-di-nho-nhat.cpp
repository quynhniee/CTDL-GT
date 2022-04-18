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
vector<vector<int> > a, dp;
int n, m;
void input () {
    cin >> n >> m;
    a.assign(n+1, vector<int>(m+1, 0));
    FOR (i, 1, n)
        FOR (j, 1, m)
            cin >> a[i][j];
}
void solve () {
    dp.assign(n+1, vector<int>(m+1, 1e6));
    dp[0][0] = 0;
    FOR (i, 1, n)
        FOR (j, 1, m)
            dp[i][j] = min (dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + a[i][j];
    cout << dp[n][m] << endl;
}
void solution () {
    input();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}