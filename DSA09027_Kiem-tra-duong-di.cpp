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

vector<vector<int> > a, res;
vector<bool> vs;
int V, E;
void BFS (int s) {
    vs.assign(V+1, false);
    queue<int> q;
    q.push(s);
    vs[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (!a[u].empty())
        FOR (i, 0, a[u].size()-1) {
            int v = a[u][i];
            if (!vs[v]) {
                res[s][v] = res[v][s] = 1;
                q.push(v);
                vs[v] = true;
            }
        }
    }
}
void input () {
    cin >> V >> E;
    a.resize(V+1);
    res.assign(V+1, vector<int> (V+1, 0));
    int i, j;
    FOR (k, 1, E) {
        cin >> i >> j;
        a[i].push_back(j);
        a[j].push_back(i);
    }
}
void test () {
    input();
    FOR (i, 1, V)
        BFS(i);
    int q;
    cin >> q;
    int i, j;
    while (q--) {
        cin >> i >> j;
        res[i][j] ? cout << "YES\n" : cout << "NO\n";
    }
    a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}