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
int c, n;
vector<int> w;
void input () {
    cin >> c >> n;
    w.assign(n+1, 0);
    FOR (i, 1, n)   cin >> w[i];
}
void solve () {
    vector<vector<int> > dp (n+1, vector<int> (c+1, 0));
    FOR (i, 1, n)
        FOR (j, 1, c)
            if (j >= w[i])
                dp[i][j] = max (dp[i-1][j], dp[i-1][j-w[i]] + w[i]);
            else    dp[i][j] = dp[i-1][j];
    cout << dp[n][c] << endl;
}
void test () {
    input();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}