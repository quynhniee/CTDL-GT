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
const long long mod = 123456789;
ll n;
ll divide (ll n) {
    if (n==0)   return 1;
    ll x = divide(n/2) % mod;
    if (n%2 == 0)   return (x * x) % mod;
    else    return ((x * x % mod) * 2) % mod;
}
void test () {
    cin >> n;
    cout << divide(n-1) << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}