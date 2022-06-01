#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<vector<int> > a, dp;
int n, m;
void init () {
    cin >> n >> m;
    a.assign(n+5, vector<int>(m+5, 0));
    dp.assign(n+5, vector<int>(m+5, -1));
    FOR (i, 1, n)
        FOR (j, 1, m)
            cin >> a[i][j];
}
void push (queue<pair<int, int> > &q, int i, int j, int fi, int se) {
    if (fi <= n && se <= m && dp[fi][se] == -1) {
        dp[fi][se] = dp[i][j] + 1;
        q.push({fi, se});
    }
}
void solve () {
    queue<pair<int, int> > q;
    q.push({1, 1});
    dp[1][1] = 0;
    while (!q.empty()) {
        int i = q.front().first, j = q.front().second;
        q.pop();
        if (i == n && j == m) {
            cout << dp[i][j] << endl;
            return;
        }
        int fi = i + abs(a[i][j] - a[i+1][j]), se = j;
        push(q, i, j, fi, se);
        fi = i, se = j + abs(a[i][j] - a[i][j+1]);
        push(q, i, j, fi, se);
        fi = i + abs(a[i][j] - a[i+1][j+1]), se = j + abs(a[i][j] - a[i+1][j+1]);
        push(q, i, j, fi, se);
    }
    cout << "-1\n";
}
void solution () {
    init();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}