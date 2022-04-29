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
vector<int> g;
int V, E;
void init () {
    cin >> V >> E;
    int u, v;
    g.assign(V+1, 0);
    FOR (i, 1, E) {
        cin >> u >> v;
        ++g[u], --g[v];
    }
}

void result () {
    FOR (i, 1, V)
        if (g[i]) {
            cout << "0\n";
            return;
        }
    cout << "1\n";
/* 
    Đồ thị có hướng liên thông G = (X, E) có chu trình Euler, khi đó 
    số đỉnh bậc trong của G sẽ bằng số đỉnh bậc ngoài của G (d+(x) = d-(x),∀xϵ X).
    => a[i] == 0
*/
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