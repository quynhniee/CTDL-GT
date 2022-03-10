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
int V, E, u, v;
vector<vector<int> > ds;

void input () {
    cin >> V >> E;
    ds.resize(V+1);
    while (E--) {
        cin >> u >> v;
        ds[u].push_back(v);
    }
}
void output () {
    FOR (i, 1, V) {
        cout << i << ":";
        for (auto j:ds[i])
            cout << " " << j;
        cout << endl;
    }
    ds.clear();
}
void test () {
    input();
    output();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}