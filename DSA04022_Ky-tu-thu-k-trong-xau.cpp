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
ll n, k;
void devide (int n) {
    ll pivot = 1 << (n-1);
    if (k == pivot) {
        cout << (char) ('A' + n - 1) << endl;
        return;
    }
    else {
        if (k > pivot) {
            k -= pivot;
        }
        devide (n-1);
    }
}
void test () {
    cin >> n >> k;
    devide(n);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}