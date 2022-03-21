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
ll n, k;
vector<ll> a;
void input () {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
}
void solve () {
    ll cou = 0;
    sort(a.begin(), a.end());
    FOR (i, 0, n-2) {
        int pos = lower_bound(a.begin() + i + 1, a.end(), a[i] + k) - a.begin();
        cou += pos - i - 1;
    }
    cout << cou << endl;
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