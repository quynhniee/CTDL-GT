
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
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<int> v[1005];
vector<bool> vs;
int V, E, u, t;
void init () {
    cin >> V >> E >> u;
    int v0, v1;
    FOR(i, 1, E) {
        cin >> v0 >> v1;
        v[v0].push_back(v1);
        v[v1].push_back(v0);
    }
}
void BFS (int s) {
    vs.resize(V+1, false);
    queue<int> q;
    q.push(s);
    vs[s] = true;
    cout << s << " ";
    while (!q.empty())
    {   
        int val = q.front();
        q.pop();
        for (auto i : v[val]) {
            if (!vs[i]) {
                q.push(i);
                cout << i << " ";
            }
            vs[i] = true;
        }
    }
    
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while (test--) {
        init ();
        BFS(u);
    }
    return 0;
}