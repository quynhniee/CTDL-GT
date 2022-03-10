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
vector<ll> a, b; 
int n;
void test () {
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    for (auto &i:a) cin >> i;
    for (auto &i:b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());
    ll sum = 0;
    FOR (i, 0, n-1)
        sum += a[i]*b[i];
    cout << sum << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}