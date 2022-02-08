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
vector<int> a;
int n;
void input () {
    cin >> n;
    a.resize(n);
    for (auto &i:a) cin >> i;
}
void solve () {
    sort(a.begin(), a.end());
    for (int i = 0; i < n/2; i++) 
        cout << a[n-1-i] << " " << a[i] << " ";
    if (n%2 == 1)   cout << a[n/2];
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
        a.clear();
    }
    return 0;
}