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
int v, e;
vector<vector<int> > g;
vector<bool> vs;
vector<int> path;
void init () {
    cin >> v >> e;
    g.clear(); g.resize(100);
    path.assign(v+1, 0);
    int a, b;
    FOR (i, 1, e) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vs.assign(v+5, false);
}
void hamilton2 (int i, int pre) {
    for (auto j:g[pre]) {
        if (i == v+1)  {
            cout << "1\n";
            return;
        }
        else if (!vs[j]) {
            vs[j] = true;
            hamilton2(i+1, j);
            vs[j] = false;
        }
    }
}
void solution () {
    init();
    vs[1] = true;
    hamilton2(2, 1);
}

void hamilton(int i) {
    int pre = path[i - 1];
    for (int t : g[pre]) {
        if (i == v + 1 and t == 1) {
            cout << "1\n" << endl;
        } else if (!vs[t]) {
            vs[t] = true;
            path[i] = t;
            hamilton(i + 1);
            vs[t] = false;
        }
    }
}

void solve() {
    init();
    path[1] = 1;
    vs[1] = true;
    hamilton(2);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solve();
    return 0;
}