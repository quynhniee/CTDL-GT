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
int n;
vector<ll> a, b;
void test () {
    cin >> n;
    a.assign(n, 0);
    b.assign(n-1, 0);
    for (auto &i:a) cin >> i;
    for (auto &i:b) cin >> i;
    FOR (i, 0, n-1) 
        if (a[i] != b[i]) {
            cout << i+1 << endl;
            return;
        }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}