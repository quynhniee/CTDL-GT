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
int n, m, res;
vector<vector<char> > a;
vector<vector<bool> > vs;
vector<int> col = {0, 1, 0, -1}, row = {-1, 0, 1, 0};
void input () {
    cin >> n >> m;
    a.clear(); a.assign(n, vector<char> (m));
    vs.assign(n, vector<bool>(m, false));
    for (auto &i:a) 
        for (auto &j:i)
            cin >> j;
}
void backtracking (int i, int j) {
    if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '#' && !vs[i][j]) {
        vs[i][j] = true;
        backtracking(i, j-1);
        backtracking(i-1, j);
        backtracking(i, j+1);
        backtracking(i+1, j);
    }
}
void solution () {
    input();
    res = 0;
    FOR (i, 0, n-1)
        FOR (j, 0, m-1) 
            if (!vs[i][j] && a[i][j] == '#') {
                ++res;
                backtracking(i, j);
            }
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}