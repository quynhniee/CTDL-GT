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
int n, s;
vector<int> a;
bool stop;
void backtracking (int i, int sum) {
    if (sum == s)   {
        stop = true;
        return;
    }
    else if (sum < s && i < n) {
        backtracking(i+1, sum + a[i]);
        backtracking(i+1, sum);
    }
}
void test () {
    cin >> n;
    s = 0;
    a.assign(n+1, 0);
    FOR (i, 0, n-1) {
        cin >> a[i];
        s += a[i];
    }
    if (s%2 != 0)   {
        cout << "NO\n";
        return;
    }
    stop = false;
    s /= 2;
    backtracking(0, 0);
    stop ?  cout << "YES\n" : cout << "NO\n";
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test();
    return 0;
}