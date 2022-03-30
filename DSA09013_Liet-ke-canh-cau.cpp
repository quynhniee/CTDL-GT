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
int V, E, x, y, components;
vector<vector<int> > g;
vector<pair<int, int> > edge;
vector<bool> vs;
void init () {
    components = 0, x = y = -1;
    cin >> V >> E;
    g.clear(); g.resize(V+5);
    edge.clear(); edge.resize(E+5);
    vs.assign(V+5, false);
    int u, v;
    FOR (i, 1, E) {
        cin >> u >> v;
        edge[i] = {u, v};
        g[u].push_back(v);
        g[v].push_back(u);
    }
}
void bfs (int s) {
    queue<int> q;
    q.push(s);
    vs[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (!g[u].empty())
        for (int v:g[u]) {
            if ((u == x && v == y) || (u == y && v == x))
                continue;
            if (!vs[v]) {
                q.push(v);
                vs[v] = true;
            }
        }
    }
}
void interconnectionComponents (int &cou) {
    FOR (i, 1, V) 
        if (!vs[i]) {
            ++cou;
            bfs(i);
        }
}
void findingBridge () {
    int cou = 0;
    vs.clear(); vs.assign(V+5, false);
    FOR (i, 1, V) 
        interconnectionComponents(cou);
    if (cou > components)
        cout << x << " " << y << " ";
}
void solution () {
    init();
    interconnectionComponents(components);
    FOR (i, 1, E) {
        x = edge[i].first, y = edge[i].second;
        findingBridge();
    }
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}