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
vector<vector<char>> a;
int c[] = {-1, 0, 1, 1, 1, 0, -1, -1}, r[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int n, m;
void init () {
    cin >> n >> m;
    a.clear(); a.resize(105, vector<char> (105));
    FOR (i, 1, n)
        FOR (j, 1, m)
            cin >> a[i][j];
}
void DFS (int x, int y) {
    FOR (i, 0, 7) {
        int col = y + c[i], row = x + r[i];
        if (col >= 1 && col <= m && row >= 1 && row <= n && a[row][col] == 'W') {
            a[row][col] = '.';
            DFS(row, col);
        }
    } 
}
void solve () {
    int cou = 0;
    FOR (i, 1, n)
        FOR (j, 1, m)
            if (a[i][j] == 'W') {
                ++cou;
                DFS(i, j);
            }
    cout << cou << endl;
}
void test_case () {
    init();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test_case();
    return 0;
}