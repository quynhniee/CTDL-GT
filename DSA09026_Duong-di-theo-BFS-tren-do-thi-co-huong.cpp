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
int V, E, s, t;
void input () {
    cin >> V >> E >> s >> t;
    a.resize(V+1);
    int i, j;
    FOR (k, 1, E) {
        cin >> i >> j;
        a[i].push_back(j);
    }
}
void output (vector<int> &x) {
    for (auto i:x)  cout << i << " ";
    cout << endl;
}
void BFS (int start, int end) {
    vector<int> rem;
    vs.assign(V+1, false);
    queue<int> q;
    q.push(start);
    rem.push_back(start);
    vs[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (!a[u].empty()) 
        FOR (i, 0, a[u].size()-1) {
            int v = a[u][i];
            if (!vs[v]) {
                rem.push_back(v);
                q.push(v);
                vs[v] = true;
                if (v == end) {
                    output(rem);
                    return;
                }
            }
        }
    }
    cout << "-1\n";
}
void test () {
    input();
    BFS(s, t);
    a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}