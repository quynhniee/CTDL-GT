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
vector<vector<int> > g;
int V, E;
void init () {
    cin >> V >> E;
    int u, v;
    g.clear(); g.resize(V+1);
    FOR (i, 1, E) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void result () {
    int cou = 0;
    FOR (i, 1, V) 
        if (g[i].size() % 2 == 0)
            ++cou;
    cou == V ? cout << "2\n" : (cou == V-2 ? cout << "1\n" : cout << "0\n");
/* 
    Đồ thị vô hướng không có điểm cô lập có chu trình Euler nếu và chỉ nếu đồ thị là liên thông và mỗi đỉnh của nó đều có bậc chẵn
    => cou == n
    Đồ thị vô hướng liên thông G = (X, E) có đường đi Euler khi và chỉ khi G có đúng hai đỉnh bậc lẻ. Nếu G có hai đỉnh bậc lẻ 
thì đường đi Euler có hai đầu đường đi nằm ở hai đỉnh bậc lẻ.   => cou == n-2
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