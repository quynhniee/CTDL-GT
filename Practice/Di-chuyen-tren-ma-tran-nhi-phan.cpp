#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <bitset>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
string a[105][105], dp[105][105];
void init () {
    cin >> n;
    FOR (i, 0, n-1)
        FOR (j, 0, n-1)
            cin >> a[i][j];
}
int binToDec (string s) {
    int res = 0;
    for (char i:s) 
        res = res * 2 + (i-'0');
    return res;
}
void binToHex (string s) {
    int num = binToDec(s);
    string res = "";
    while (num > 0) {
        int mod = num % 16;
        res += (mod < 10) ? (char)(mod + '0') : (char)(mod - 10 + 'A');
        num /= 16;
    }
    reverse(res.begin(), res.end());
    cout << res;
}
void solve () {
    dp[0][0] += a[0][0];
    FOR (i, 1, n-1) {
        dp[0][i] = dp[0][i-1] + a[0][i];
        dp[i][0] = dp[i-1][0] + a[i][0];
    }
    FOR (i, 1, n-1)
        FOR (j, 1, n-1)
            dp[i][j] = max (dp[i][j-1], dp[i-1][j]) + a[i][j];
    string s = dp[n-1][n-1];
    while (s.size()%4 != 0) s = "0" + s;
    for (int i = 0; i < s.size(); i+=4) {
        string tmp = s.substr(i, 4);
        binToHex(tmp);
    }
}
void solution () {
    init();
    solve();
    
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}