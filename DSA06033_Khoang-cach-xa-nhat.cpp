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
int n, len;
vector<int> a;
void input () {
    cin >> n;
    a.resize(n);
    for (auto &i:a) cin >> i;
    len = n;
}
void solve () {
    while (len--) {
        for (int i = 0; i < n - len; i++) 
            if (a[i] < a[i + len])  {
                cout << len << endl;
                return;
            }       
    }
    cout << len << endl;
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
    }
    return 0;
}