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
int n;
vector<string> ans;
vector<char> s = {'D', 'L', 'R', 'U'};
vector<int> col = {0, -1, 1, 0}, row = {1, 0, 0, -1};
void init () {
    cin >> n;
    ans.clear();
    a.assign(n, vector<int> (n, 0));
    vs.assign(n, vector<int> (n, 0));
    for (auto &i:a)
        for (auto &j:i)
            cin >> j;
}
void backtracking (int i, int j, string rem) {
    FOR (k, 0, 3) {
        int c = j + col[k], r = i + row[k];
        if (c >= 0 && c < n && r >= 0 && r < n && a[r][c] && !vs[r][c]) {
            if (r == n-1 && c == n-1) {
                ans.push_back( rem + s[k]);
            }
            vs[r][c] = 1;
            backtracking(r, c, rem + s[k]);
            vs[r][c] = 0;
        }
    }
}
void output () {
    if (ans.empty()) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << " ";
    for (auto i:ans)    cout << i << " ";
    cout << endl;
}
void test () {
    init();
    vs[0][0] = 1;
    backtracking(0, 0, "");
    output();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}