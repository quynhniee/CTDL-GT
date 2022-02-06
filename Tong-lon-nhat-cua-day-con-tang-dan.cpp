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
vector<int> a, s;
int n;
void init () {
    cin >> n;
    a.resize(n), s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i];
    }
}
void solve () {
    for (int i = 1; i < n; i++) 
        for (int j = 0; j < i; j++)
            if (a[i] > a[j] && s[j] + a[i] > s[i])
                s[i] = s[j] + a[i];
                
    cout << *max_element(s.begin(), s.end()) << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        init();
        solve();
        a.clear();
        s.clear();
    }
    return 0;
}