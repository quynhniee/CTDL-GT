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
int n, m, s, t;
vector<vector<int> > g;
vector<bool> vs;
vector<int> trace;
void init () {
    cin >> n >> m >> s >> t;
    g.clear(); g.resize(n+1);
    int a, b;
    FOR (i, 1, m) {
        cin >> a >> b;
        g[a].push_back(b);
    }
}
void bfs (int s) {
    vs.assign(n+1, false);
    trace.assign(n+1, -1);
    vs[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v:g[u]) 
            if (!vs[v]) {
                vs[v] = true;
                trace[v] = u;
                q.push(v);
            }
    }
}
void result () {
    if (!vs[t]) {
        cout << "-1\n";
        return;
    }
    vector<int> step;
    int prevStep = t;
    while (prevStep != -1) {
        step.push_back(prevStep);
        prevStep = trace[prevStep];
    }
    FORD (i, step.size()-1, 0) 
        cout << step[i] << " ";
    cout << endl;
}
void solution () {
    init();
    bfs(s);
    result();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}