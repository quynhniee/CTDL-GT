
#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
bool prime (long long n) {
    if (n<2)    return 0;
    if (n%2 == 0 && n>2)    return 0;
    for (int i=3; i<=sqrt(n); i+=2) {
        if (n%i == 0)   return false;
    }
    return true;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    ll n;
    while (t--) {
        cin >> n;
        prime(n) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}