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
vector<vector<int> > a;
vector<bool> vs;
int V, E, u, v;
void init () {
    cin >> V >> E;
    a.clear(); a.resize(V+2);
    FOR (i, 1, E) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vs.assign(V+1, false);
}
void BFS (int s) {
    queue<int> q;
    q.push(s);
    vs[s] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (!a[u].empty())
        for (auto v:a[u]) 
            if (!vs[v]) {
                vs[v] = true;
                q.push(v);
            }    
    }
}
void count () {
    int cou = 0;
    FOR (i, 1, V) 
        if (!vs[i]) {
            ++cou;
            BFS(i);
        }
    cout << cou << endl;
}
void test () {
    init();
    count();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}