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
int n, k;
vector<int> a;
void test () {
    cin >> n >> k;
    a.assign(n+1, 0);
    FOR (i, 1, n) {
        cin >> a[i];
        a[i] %= k;
    }
    vector<vector<int> > m (n+1, vector<int> (k, 0));
    FOR (i, 1, k-1) m[1][i] = -100000;
    m[1][a[1]] = 1;
    FOR (i, 2, n) 
        FOR (j, 0, k-1)
            m[i][j] = max(m[i-1][j], m[i-1][(j + k - a[i]) % k] + 1);
            // để sau khi cộng a[i] vào được số dư là j
    cout << m[n][0] << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}