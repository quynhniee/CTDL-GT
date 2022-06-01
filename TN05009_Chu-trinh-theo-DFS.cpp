#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int v, e;
vector<vector<int>> g;
vector<bool> vs;
vector<int> path, ans;
bool isValid;
void init () {
    isValid = false;
    cin >> v >> e;
    path.clear(); ans.clear();
    vs.assign(v+100, false);
    g.clear(); g.resize(v+100);
    while (e--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    FOR (i, 1, v)
        sort(g[i].begin(), g[i].end());

}
void DFS (int u, int pre) {
    vs[u] = true;
    for (auto v:g[u]) {
        if (v != pre && v == 1 && ans.empty()) {
            path.push_back(v);
            ans = path;
            isValid = true;
            return;
        }
        if (!vs[v]) {
            path.push_back(v);
            DFS (v, u);
            path.pop_back();
        }
    }
}
void test_case () {
    init();
    path.push_back(1);
    DFS (1, 0);
    if (!isValid)   cout << "NO\n";
    else {
        for (auto i:ans)   cout << i << " ";
        cout << endl;
    }
}
int main () {
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test_case();
    return 0;
}