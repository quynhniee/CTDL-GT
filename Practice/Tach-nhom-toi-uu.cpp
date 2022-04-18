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
int n, k;
vector<int> a;
void init () {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
}
void solve () {
    sort(a.begin(), a.end());
    int groups = 1;
    FOR (i, 1, n-1)
        if (a[i] > a[i-1] + k)
            ++groups;
    cout << groups << endl;
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