#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<vector<int> > g;
vector<pair<int, int> > res;
vector<bool> vs;
int n, m, u, cou;
void init () {
    cin >> n >> m >> u;
    g.clear(); g.resize(n+1);
    int a, b;
    FOR (i, 1, m) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vs.assign(n+1, false);
    res.clear();
    cou = 1;
}
void bfs (int u) {
    vs[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto v:g[s])
            if (!vs[v]) {
                res.push_back({s, v});
                vs[v] = true;
                q.push(v);
                ++cou;
            }
    }
}
// Một cây khung là một tập con của Grahp G mà có tất cả các đỉnh được bao bởi số cạnh tối thiểu nhất.
void output () {
    if (cou < n) {
        cout << "-1\n";
        return;
    }
    for (auto i:res)    
        cout << i.first << " " << i.second << endl;
}
void solution () {
    init();
    bfs(u);
    output();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}