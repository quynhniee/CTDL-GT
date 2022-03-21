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
ll n, k, s;
vector<ll> a;
void input () {
    s = 0;
    cin >> n >> k;
    a.assign(n+1, 0);
    FOR (i, 1, n) {
        cin >> a[i];
        a[i] += a[i-1];
    }
}
void solve () {
    FOR (i, 0, n)
        if (binary_search(a.begin() + 1 + i, a.end(), a[i] + k)) {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
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