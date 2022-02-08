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
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<pair<int, int> > a;
int n, cou;

void init () {
    cin >> n;
    a.resize(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    cou = 0;
}
void solve () {
    stable_sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        while (a[i].second != i) {
            swap (a[i], a[a[i].second]);
            ++cou;
        }
    }
    cout << cou << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        init ();
        solve();
    }
    return 0;
}