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
vector<vector<int> > a;
vector<bool> vs;

void DFS (int start) {
    stack<int> st;
    cout << start << " ";
    st.push(start);
    vs[start] = true;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!a[u].empty())
        FOR (i, 0, a[u].size()-1) {
            int v = a[u][i];
            if (!vs[v]) {
                cout << v << " ";
                vs[v] = true;
                st.push(u);
                st.push(v);
                break;
            }
        }
    }
}

int V, E, u;
void input () {
    cin >> V >> E >> u;
    a.resize(V+1);
    vs.assign(V+1, false);
    int i, j;
    FOR (k, 1, E) {
        cin >> i >> j;
        a[i].push_back(j);
    }
}
void test () {
    input();
    DFS(u);
    cout << endl;
    a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}