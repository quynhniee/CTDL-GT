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
vector<vector<int> > g;
vector<bool> vs;
bool valid;
int n, m;
void init () {
    cin >> n >> m;
    g.clear(); g.resize(n+1);
    int a, b;
    FOR (i, 1, m) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    valid = false;
}
void bfs (int s) {
    if (valid)  return;
    vs.assign(n+1, false);
    queue<pair<int, int> > q;
    q.push({s, 0}); vs[s] = true;
    while (!q.empty()) {
        int u = q.front().first; 
        int pre = q.front().second;
        q.pop();
        for (auto v:g[u]) 
            if (!vs[v]) {
                vs[v] = true;
                q.push({v, u});
            }
            else if (v != pre)  {
                valid = true;
                return;
            }
    }
}
void result () {
    FOR (i, 1, n) {
        bfs(i);
        if (valid)  break;
    }
    valid ? cout << "YES\n" : cout << "NO\n";
}
void solution () {
    init();
    result();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}