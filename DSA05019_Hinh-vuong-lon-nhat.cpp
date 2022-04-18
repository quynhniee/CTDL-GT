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
vector<vector<int> > a, c;
int n, m;
void dp () {
    c.assign(505, vector<int>(505, 0));
    int res = 0;
    FOR (i, 1, m)   c[0][i] = a[0][i];
    FOR (i, 1, n)   c[i][0] = a[i][0];
    FOR (i, 1, n)
        FOR (j, 1, m) {
            c[i][j] = (a[i][j]) ? min(c[i-1][j], min(c[i-1][j-1], c[i][j-1])) + 1 : 0;
            res = max (res, c[i][j]);
        }
    cout << res << endl;
}
void solution () {
    cin >> n >> m;
    a.assign(n+2, vector<int>(m+2, 0));
    FOR (i, 1, n)
        FOR (j, 1, m)
            cin >> a[i][j];
    dp();
}
int main () {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}