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
int n, m;
vector<int> a, b; 
void input () {
    cin >> n >> m;
    a.assign(n, 0);
    b.assign(m, 0);
    for (auto &i:a) cin >> i;
    for (auto &i:b) cin >> i;
}
void solve () {
    vector<int> res (n+m-1, 0);
    FOR (i, 0, n-1) 
        FOR (j, 0, m-1)
            res[i+j] += a[i]*b[j];
    for (auto i:res)    cout << i << " ";
    cout << endl;
}
void test () {
    input();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}