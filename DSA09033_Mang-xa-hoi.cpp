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
vector<bool> vs;
vector<vector<int>> g;
void init () {
    cin >> n >> m;
    vs.assign(n+1, false);
    g.clear(); g.resize(n+1);
    int u, v;
    FOR (i, 1, m) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
void dfs (int u) {
    vs[u] = true;
    for (auto v:g[u])
        if (!vs[v])
            dfs(v);
}
bool check () {
    FOR (i, 1, n)
        if (!vs[i])
            return false;
    return true;
}
void solution () {
    init();
    dfs(1);
    check() ? cout << "YES\n" : cout << "NO\n";
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}