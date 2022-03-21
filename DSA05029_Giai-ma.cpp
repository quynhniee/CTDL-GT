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
int to_int (char x, char y) {
    return (x-'0')*10 + (y-'0');
}
void test () {
    cin >> s;
    int n = s.size();
    if (s[0] == '0') {
        cout << "0\n";
        return;
    }
    vector<ll> dp (n+1, 0);
    s = "0" + s;
    dp[0] = dp[1] = 1;
    FOR (i, 2, n) {
        if (s[i] == '0') {
            if (s[i-1] > '2') {
                cout << "0\n";
                return;
            }
            dp[i] = dp[i-2];
        }
        else
            dp[i] = to_int(s[i-1], s[i]) > 26 ? dp[i-1] : dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}