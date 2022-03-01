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
int n, W, fopt;
// n là số đồ vật, W là thể tích tối đa
vector<int> a, c, f, xopt;
// a là thể tích, c là giá trị
void input () {
    cin >> n >> W;
    a.assign(n, 0), c.assign(n, 0), f.assign(n, 0);
    for (auto &i:c) cin >> i;
    for (auto &i:a) cin >> i;
}
void backtrack (int i, int w, int v) {
    if (i == n && v > fopt && w <= W) {
        fopt = v;
        xopt = f;
    }
    else if (i < n && w <= W) {
        f[i] = 0;
        backtrack(i+1, w, v);
        f[i] = 1;
        backtrack(i+1, w + a[i], v + c[i]);
    }
}
void test () {
    input ();
    backtrack(0, 0, 0);
    cout << fopt << endl;
    for (auto i:xopt)   cout << i << " ";
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test ();
    return 0;
}