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
vector<vector<int> > a;
int col[] = {-1, 0, 1, 1, 1, 0, -1, -1}, row[] = {-1, -1, -1, 0, 1, 1, 1, 0};
void init () {
    cin >> n >> m;
    a.assign(n, vector<int> (m, 0));
    FOR (i, 0, n-1)
        FOR (j, 0, m-1)
            cin >> a[i][j];
}
void dfs (int i, int j) {
    FOR (k, 0, 7) {
        int r = i + row[k], c = col[k] + j;
        if (r >= 0 && r < n && c >= 0 && c < m && a[r][c]) {
            a[r][c] = 0;
            dfs(r, c);
        }
    }
}
void solution() {
    init();
    int res = 0;
    FOR (i, 0, n-1)
        FOR (j, 0, m-1)
            if (a[i][j]) {
                ++res; 
                dfs(i, j);
            }
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}