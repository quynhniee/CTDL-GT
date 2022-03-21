#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <stack>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
vector<int> a;
void test () {
    cin >> n;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
    vector<int> dp (n, 1);
    int arranged = 0;
    FOR (i, 1, n-1)
        FOR (j, 0, i-1)
            if (a[j] <= a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                arranged = max(arranged, dp[i]);
            }
    cout << n - arranged << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}