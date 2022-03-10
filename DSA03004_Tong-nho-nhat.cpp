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
vector<int> digit;
void input () {
    cin >> n;
    digit.assign(n, 0);
    for (auto &i:digit) cin >> i;
    sort(digit.begin(), digit.end());
}
ll calculate (ll s, int l) {
    for (int i = l; i < n; i += 2)
        s = s*10 + digit[i];
    return s;
} 
void test () {
    input ();
    cout << calculate(0, 0) + calculate(0, 1) << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}