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
bool check;
void init () {
    cin >> v >> e;
    g.clear(); g.resize(100);
    path.assign(100, 0);
    int a, b;
    FOR (i, 1, e) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    check = false;
}
void hamilton(int i) {
    if (i == v)   
        check = true;
    else 
        for (auto j:g[path[i-1]]) 
            if (!vs[j]) {
                path[i] = j;
                vs[j] = true;
                hamilton(i+1);
                vs[j] = false;
            }
}

void solve() {
    init();
    FOR (i, 1, v) {
        vs.assign(100, false);
        vs[i] = true;
        path[0] = i;
        hamilton (1);
        if (check)  break;
    } 
    cout << check << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solve();
    return 0;
}