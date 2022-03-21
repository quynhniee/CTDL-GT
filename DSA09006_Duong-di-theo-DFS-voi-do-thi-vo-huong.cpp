#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <stack>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int V, E, s, t, u, v;
vector<vector<int> > a;
vector<int> vs, mark;
void init () {
    cin >> V >> E >> s >> t;
    a.resize(V+1);
    FOR (i, 0, E-1) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}
void DFS (int s) {
    vs.assign(V+1, 0);
    mark.assign(V+1, -1);
    stack<int> st;
    st.push(s);
    vs[s] = 1;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (u == t) return;
        if (!a[u].empty())
        FOR (i, 0, a[u].size()-1) {
            int v = a[u][i];
            if (!vs[v]) {
                st.push(u);
                st.push(v);
                vs[v] = 1;
                mark[v] = u;
                break;
            }
        }
    }
}
void trace () {
    if (!vs[t]) {
        cout << "-1\n";
        return;
    }
    vector<int> step;
    int prevStep = t;
    while (prevStep != -1) {
        step.push_back(prevStep);
        prevStep = mark[prevStep];
    }
    FORD (i, step.size()-1, 0)
        cout << step[i] << " ";
    cout << endl;
}
void test () {
    init();
    DFS(s);
    trace();
    a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}