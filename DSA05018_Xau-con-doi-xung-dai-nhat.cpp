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
string s;
bool check (int l, int r) {
    r -= l;
    FOR (i, 0, r/2)
        if (s[l + i] != s[l + r - i]) return false;
    return true;
}
void test () {
    cin >> s;
    int n = s.size();
    int res = 1;
    FOR (i, 0, n-1)
        if (i+res < n)
        FOR (j, i+res, n-1)
            if (check(i, j))
                res = j-i+1;
    cout << res << endl;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}