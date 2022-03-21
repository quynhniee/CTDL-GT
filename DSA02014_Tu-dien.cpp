#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<int> row = {-1, -1, -1, 0, 0, 1, 1, 1}, col = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<vector<string> > a;
vector<string> ans;
vector<vector<int> > vs;
unordered_map<string, int> dic;
int n, m, k;
void init () {
    cin >> k >> n >> m;
    a.assign(n, vector<string>(m, ""));
    vs.assign(n, vector<int> (m, 0));
    string s;
    while (k--) {
        cin >> s;
        dic[s] = 1;
    }
    for (auto &i:a) 
        for (auto &j:i)
            cin >> j;
}
void backtrack (int i, int j, string s) {
    if (dic[s]) ans.push_back(s);
    FOR (l, 0, 7) {
        int r = row[l] + i, c = col[l] + j;
        if (r >= 0 && r < n && c >= 0 && c < m && !vs[r][c]) {
            vs[r][c] = 1;
            backtrack(r, c, s + a[r][c]);
            vs[r][c] = 0;
        }
    }
}
void output () {
    if (ans.empty()) {
        cout << "-1\n";
        return;
    }
    for (auto i:ans)    cout << i << " ";
    cout << endl;
}
void test () {
    init();
    FOR (i, 0, n-1)
        FOR (j, 0, m-1) {
            vs[i][j] = 1;
            backtrack(i, j, a[i][j]);
            vs[i][j] = 0;
        }
    output();
    ans.clear();
    dic.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}