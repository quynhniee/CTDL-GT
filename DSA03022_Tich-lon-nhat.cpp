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
void calculate () {
    sort(a.begin(), a.end());
    ll x1 = a[0] * a[1];
    ll x2 = a[n-1] * a[n-2];
    ll x3 = x1 * a[n-1];
    ll x4 = x2 * a[n-3];
    cout << max(max(x2, x2), max(x3, x4)) << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input();
    calculate();
    return 0;
}