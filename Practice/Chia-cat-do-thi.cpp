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
vector<int> vs;
vector<vector<int> > g;
int n, m, stplt, res;
void init () {
    cin >> n >> m;
    int a, b;
    g.clear(); g.resize(n+1);
    FOR (i, 1, m) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}
void bfs (int s) {
    vs[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v:g[u]) 
            if (!vs[v]) {
                vs[v] = true;
                q.push(v);
            }
    }
}
void solve () {
    int res = 0, stplt = 1;
    FOR (i, 1, n) {
        vs.assign(n+1, false);
        int cou = 0;
        vs[i] = true;
        FOR (j, 1, n)
            if (!vs[j]) {
                bfs(j);
                ++cou;
            }
        if (cou > stplt) {
            stplt = cou;
            res = i;
        }
    }
    cout << res << endl;
}
void solution () {
    init();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()       solution();
    return 0;
}