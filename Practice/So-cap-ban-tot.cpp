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
vector<int> length;
vector<string> name;
int n, k;
void init () {
    cin >> n >> k;
    name.clear(); name.resize(n);
    length.assign(100, 0);
    for (auto &i:name)  cin >> i;
}
void solve () {
    ll res = 0;
    FOR (i, 0, k) {
        res += length[name[i].size()];
        ++length[name[i].size()];
    }
    FOR (i, k+1, n-1) {
        --length[name[i-k-1].size()];
        res += length[name[i].size()];
        ++length[name[i].size()];
    }
    cout << res << endl;
}
void solution () {
    init();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}