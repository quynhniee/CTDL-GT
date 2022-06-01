#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <stack>
#include <queue>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int k, n, m, res;
vector<bool> vs;
vector<vector<int>> g;
vector<int> a;
void init () {
    cin >> k >> n >> m;
    a.assign(k, 0);
    for (auto &i:a) cin >> i;
    g.clear(); g.resize(n+100);
    while (m--) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y); 
    }
    res = 0;
}
void BFS (int s) {
    vs.assign(n+100, false);
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
bool check () {
    for (auto i:a)
        if (!vs[i]) return false;
    return true;
}
void testc_case () {
    init();
    FOR (i, 1, n) {
        BFS (i);
        if (check())    ++res;
    }
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    testc_case();
    return 0;
}