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
vector<vector<int> > a, vs;
int c[] = {0, 1}, r[] = {1, 0};
int n;
string trace;
ll res;
void init () {
    cin >> n;
    a.assign(n, vector<int>(n, 0));
    vs.assign(n, vector<int>(n, 0));
    for (auto &i:a)
        for (auto &j:i)
            cin >> j;
}
void solve (int i, int j) {
    if (i == n-1 && j == n-1) {
        res = max (res, stoll(trace,0 , 2));
    }
    else if (i < n && j < n)
    FOR (k, 0, 1) {
        int row = i + r[k], col = c[k] + j;
        if (row >= 0 && row < n && col >= 0 && col < n && !vs[row][col]) {
            vs[row][col] = 1;
            trace += to_string(a[row][col]);
            solve(row, col);
            trace.pop_back();
            vs[row][col] = 0;
        }
    }
}
void solution () {
    init();
    vs[0][0] = 1;
    solve(0, 0);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}