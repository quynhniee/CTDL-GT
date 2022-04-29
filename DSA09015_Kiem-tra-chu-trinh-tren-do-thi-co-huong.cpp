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
vector<int> vs;
bool valid;
int n, m;
void init () {
    cin >> n >> m;
    g.clear(); g.resize(n+1);
    vs.assign(n+1, 0);
    int a, b;
    FOR (i, 1, m) {
        cin >> a >> b;
        g[a].push_back(b);
    }
    valid = false;
}
void dfs (int s) {
    vs[s] = 1;
    for (auto i:g[s]) 
        if (!vs[i])
            dfs(i);
        else if (vs[i] == 1)
            valid = true;
    vs[s] = 2;
}
void result () {
    FOR (i, 1, n) 
        if (!vs[i] && !valid)
            dfs(i);
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