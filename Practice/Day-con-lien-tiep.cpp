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
vector<ll> a;
int n;
void test () {
    cin >> n;
    a.assign(n+1, 0);
    FOR (i, 1, n) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    db average = 0, s;
    int res = 0;
    FOR (i, 0, n-2)
        FOR (j, i+2, n) {
            s = 1.0 * (a[j] - a[i]) / (j - i);
            if (s > average) {
                average = s;
                res = j - i;
            }
            else if (s == average)
                res = max(res, j - i);
        }
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}