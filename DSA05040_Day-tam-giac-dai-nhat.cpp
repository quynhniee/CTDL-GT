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
int n;
vector<int> a;
void input () {
    cin >> n;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
}
void solve () {
    vector<int> incr(n, 0), decr(n, 0);
    FOR (i, 1, n-1)
        if (a[i] > a[i-1])
            incr[i] = incr[i-1] + 1;
    FORD (i, n-2, 0)
        if (a[i] > a[i+1])
            decr[i] = decr[i+1] + 1;
    int res = 0;
    FOR (i, 0, n-1)
        res = max (res, decr[i] + incr[i] + 1);
    cout << res << endl;
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