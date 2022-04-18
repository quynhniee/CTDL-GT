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
string s;
void test_case () {
    cin >> s;
    vector<ll> dp(15, 0);
    s = "0" + s;
    dp[1] = s[1] - '0';
    ll sum = dp[1];
    FOR (i, 2, s.size()-1) {
        dp[i] = dp[i-1]*10 + i*(s[i]-'0');
        sum += dp[i];
    }
    cout << sum << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test_case();
    return 0;
}