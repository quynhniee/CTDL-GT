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
ll n, x;
vector<ll> a;
void input () {
    cin >> n >> x;
    a.assign(n+1, 0);
    FOR (i, 1, n)   cin >> a[i];
}
void solve () {
    ll pos = 0;
    FOR (i, 1, n) 
        if (a[i] <= x && a[i] > a[pos])
            pos = i;
    !pos ? cout << "-1\n" : cout << pos << endl;
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