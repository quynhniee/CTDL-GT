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
vector<db> a, b;
vector<ll> decr, incr;
void output (vector<ll> x) {
    for (auto i:x)  cout << i << " ";
    cout << endl;
}
void solution () {
    cin >> n;
    a.assign(n, 0), b.assign(n, 0), decr.assign(n, 1), incr.assign(n, 1);
    FOR (i, 0, n-1)
        cin >> a[i] >> b[i];
    FOR (i, 1, n-1)
        FOR (j, 0, i-1)
            if (a[i] > a[j])    incr[i] = max (incr[i], incr[j]+1);
    FOR (i, 1, n-1)
        FOR (j, 0, i-1)
            if (b[i] < b[j])    decr[i] = max (decr[i], decr[j]+1); 
    output(incr), output(decr); 
    ll res = 0;
    FOR (i, 0, n-1)
        res = max (res, min(incr[i], decr[i]));
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}