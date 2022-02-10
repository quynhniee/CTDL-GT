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
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;

int n;

void test () {
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a)   cin >> i;
    sort(a.begin(), a.end());
    ll ans = mod;
    for (int i = 0; i < n-1; i++) 
        ans = min (ans, abs(a[i+1] - a[i]));
    cout << ans << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}