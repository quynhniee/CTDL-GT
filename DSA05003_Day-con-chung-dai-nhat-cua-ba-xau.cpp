#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int dp[105][105][105];
int n, m, p;
string s1, s2, s3;
void dynamicProgram () {
    memset(dp, 0, sizeof(dp));
    FOR (i, 1, m)
        FOR (j, 1, n)
            FOR (k, 1, p)
                dp[i][j][k] = (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) ? dp[i-1][j-1][k-1] + 1 : max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
    cout << dp[m][n][p] << endl;
}
void solution () {
    cin >> m >> n >> p >> s1 >> s2 >> s3;
    dynamicProgram();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}