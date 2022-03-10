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
vector<ll> fibo {0, 1, 1};
void fibonacciVector () {
    FOR (i, 3, 92) 
        fibo.push_back(fibo[i-1] + fibo[i-2]);
}
ll n, k;
void solve () {
    if (n <= 2) cout << (char)('A' + n - 1) << endl;
    else {
        if (k > fibo[n-2])  {
            k -= fibo[n-2];
            n--;
        }
        else n -= 2;
        solve();
    } 
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    fibonacciVector();
    tester() {
        cin >> n >> k;
        solve();
    }
    return 0;
}