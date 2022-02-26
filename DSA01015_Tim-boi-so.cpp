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
ll res;
void multiple (ll val) {
    if (val > res) return;
    else if (val % n == 0) {
        res = min(res, val);
        return;
    }
    else {
        multiple(val * 10);
        multiple(val * 10 + 9);
    }
}
void test () {
    res = 1e18;
    cin >> n;
    multiple(9);
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test();
    return 0;
}