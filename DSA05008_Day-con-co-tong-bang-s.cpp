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
int n, s;
vector<int> a;
void input () {
    cin >> n >> s;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
}
void solve () {
    vector<int> dp (s+1, 0);
    dp[0] = 1;
    FOR (i, 0, n-1)
        FORD(j, s, a[i])
            if (!dp[j] && dp[j-a[i]])
                dp[j] = 1;
    dp[s] ? cout << "YES\n" : cout << "NO\n";
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