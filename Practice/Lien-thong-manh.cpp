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
int n, m, cnt, stpltm;
vector<vector<int> > g;
vector<int> low, num;
stack<int> st;
void init () {
    cin >> n >> m;
    int a, b;
    low.assign(n+5, INT_MAX), num.assign(n+5, INT_MAX);
    cnt = stpltm = 0;
    g.clear(); g.resize(n+5);
    FOR (i, 1, m) {
        cin >> a >> b;
        g[a].push_back(b);
    }
}
void tarjan (int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (auto v:g[u]) {
        if (num[v]) // nếu đỉnh này đã được đi qua
            low[u] = min (low[u], num[v]);
        else {
            tarjan(v);
            low[u] = min (low[u], low[v]);  
        }
    }
    if (num[u] == low[u]){ 
        ++stpltm;
        int tmp;
        do {
            tmp = st.top();
            st.pop();
            num[tmp] = low[tmp] = INT_MAX;
        }
        while (tmp != u)
    }
}
void solution () {
    init();
    FOR (i, 1, n)
        if (!num[i])
            tarjan(i);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}