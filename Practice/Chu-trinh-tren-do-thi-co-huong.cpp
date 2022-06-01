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
vector<int> vs;
vector<vector<int> > g;
int n, m;
bool valid;
void init () {
    cin >> n >> m;
    g.clear(); g.resize(n+1);
    valid = false;
    vs.assign(n+1, 0);
    int a, b;
    FOR (i, 1, m) {
        cin >> a >> b;
        g[a].push_back(b);
    }
}
void dfs (int s) {
    vs[s] = 1;
    for (auto t:g[s]) 
        if (!vs[t]) dfs(t);
        else if (vs[t] == 1) valid = true;
    vs[s] = 2;
}
void solution () {
    init();
    FOR (i, 1, n)
        if (!vs[i] && !valid)
            dfs(i);
    cout << (valid ? "YES\n" : "NO\n");
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}