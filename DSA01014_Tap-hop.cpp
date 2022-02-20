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
int n, k, s, sum;
ll cou;
void backtracking (int i, int val) {
    FOR (j, val+1, n) {
        sum += j;
        if (i == k-1) {
            if (sum == s)
                ++cou;
        }
        else if (sum < s)
            backtracking(i+1, j);
        sum -= j;
    }
}
void test () {
    cin >> n >> k >> s;
    if (n == 0 && k == 0 && s == 0)
        return;
    sum = 0;
    cou = 0;
    backtracking(0, 0);
    cout << cou << endl;
    test();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}