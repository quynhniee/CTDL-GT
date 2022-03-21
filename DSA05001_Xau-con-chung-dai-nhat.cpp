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
string a, b; 
vector<vector<int> > dp;
void test () {
    cin >> a >> b; 
    dp.assign(1005, vector<int>(1005, 0));
    int res = 0;
    FOR (i, 1, a.size()) {
        FOR (j, 1, b.size()) {
            if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}