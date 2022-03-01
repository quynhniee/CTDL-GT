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
ll s, sum, cou, res;
vector<ll> a;
void init () {
    cin >> n >> s;
    sum = cou = 0;
    res = 1e9;
    a.assign(n, 0);
    FOR (i, 0, n-1) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
}
void backtracking (int i) {
    FOR (j, i, n-1) {
        sum += a[j];
        ++cou;
        if (sum == s) {
            res = min (res, cou);
        }  
        else if (sum < s && i < n) backtracking(j+1);
        sum -= a[j];
        --cou;
    }
}
void test () {
    init();
    backtracking(0);
    res != 1e9 ? cout << res << endl : cout << "-1\n";
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test();
    return 0;
}