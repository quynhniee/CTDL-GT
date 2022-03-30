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
vector<vector<int> > a;
vector<int> mainn, sub, col;
int res, p;
void init () {
    res = p = 0;
    a.assign(9, vector<int> (9, 0));
    mainn.assign(17, 0), sub.assign(17, 0), col.assign(9, 0);
    FOR (i, 1, 8)
        FOR (j, 1, 8)
            cin >> a[i][j];
}
void backtracking (int i) {
    FOR (j, 1, 8) 
        if (!col[j] && !mainn[i+j-1] && !sub[i-j+8]) {
            col[j] = 1, mainn[i+j-1] = 1, sub[i-j+8] = 1;
            p += a[i][j];
            if (i == 8)
                res = max (res, p);
            else
                backtracking(i+1);
            col[j] = 0, mainn[i+j-1] = 0, sub[i-j+8] = 0;
            p -= a[i][j];
        }
}
void test () {
    init();
    backtracking(1);
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t1;
    cin >> t1;
    FOR (t, 1, t1) {
        cout << "Test " << t << ": ";
        test();
    }
    return 0;
}