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
ll a, b;
ll divide (ll a, ll b) {
    if (b == 0) return 1;
    ll x = divide(a, b/2) % mod;
    if (b%2 == 1)   return ((x * x % mod) * a) % mod;
    else    return (x * x) % mod;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    while (a != 0 || b != 0) {
        cout << divide (a, b) << endl;
        cin >> a >> b; 
    }
    return 0;
}