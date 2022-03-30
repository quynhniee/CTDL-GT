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
int V, E, components;
vector<vector<int> > g;
vector<bool> vs;
void init () {
    components = 0;
    cin >> V >> E;
    g.clear(); g.resize(V+5);
    vs.assign(V+5, false);
    int x, y;
    FOR (i, 1, E) {
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
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
void findingJoint (int s) {
    int cou = 0;
    vs.clear(); vs.assign(V+5, false);
    vs[s] = true;
    FOR (i, 1, V) 
        if (!vs[i])
            interconnectionComponents(cou);
    if (cou > components)
        cout << s << " ";
}
void solution () {
    init();
    interconnectionComponents(components);
    FOR (i, 1, V)
        findingJoint (i);
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester() solution();
    return 0;
}