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
int x, y, z, n;
void calculate () {
    vector<int> f (n+3, 0);
    f[1] = x;
    FOR (i, 2, n)
        f[i] = (i%2 == 0) ? min (f[i-1] + x, f[i/2] + z) : min (f[i-1] + x, f[(i+1)/2] + y + z);
    cout << f[n] << endl;
}
void test () {
    cin >> n >> x >> y >> z;
    calculate();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}