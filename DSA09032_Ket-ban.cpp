#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <queue>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, m, res;
vector<vector<int> > g;
vector<int> vs;
void init () {
    cin >> n >> m;
    g.clear(); g.resize(n+1);
    int a, b;
    while (m--) {
        cin >> a >> b;
        if (find(g[a].begin(), g[a].end(), b) != g[a].end())
        g[a].push_back(b);
    }
    res = 0;
}
void bfs (int s) {
    int cou = 1;
    vs.resize(n+1, 0);
    vs[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v:g[u]) 
            if (!vs[v]) {
                vs[v] = 1;
                ++cou;
                q.push(v);
            }
    }
    cout << cou << " ";
}
void solution () {
    init();
    FOR (i, 1, n)
        bfs(i);
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}