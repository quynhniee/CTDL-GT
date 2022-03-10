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

ll exponentiation (ll n, ll k) {
    if (k == 0) return 1;
    else {
        ll val = exponentiation(n, k/2) % mod;
        if (k%2 == 0)   return val * val % mod;
        else    return ((val * n) % mod * val) % mod;
    }
}
void test () {
    ll n, k;
    cin >> n >> k;
    cout << exponentiation(n, k) << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}