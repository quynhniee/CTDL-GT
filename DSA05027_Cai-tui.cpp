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
int N, V;
vector<int> w, v; 
void input () {
    cin >> N >> V;
    w.assign(N+1, 0);
    v.assign(N+1, 0);
    FOR (i, 1, N)   cin >> w[i];
    FOR (i, 1, N)   cin >> v[i];
}
void solve () {
// dp[i][j] là giá trị lớn nhất khi chọn đến gói hàng thứ i, với khối lượng tối đa là j
    vector<vector<int> > dp (N+1, vector<int> (V+1, 0));
    FOR (i, 1, N) 
        FOR (j, 1, V)
            if (j >= w[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            else    dp[i][j] = dp[i-1][j];
    cout << dp[N][V] << endl;
}
void test () {
    input();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}