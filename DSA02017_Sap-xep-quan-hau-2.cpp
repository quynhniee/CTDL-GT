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
vector<int> col, l, r;
int point, res;
void init () {
    a.resize(8, vector<int> (8));
    FOR (i, 0, 7)
        FOR (j, 0, 7)
            cin >> a[i][j];
    l.resize(2*8 - 1, 1);
    r.resize(2*8 - 1, 1);
    col.resize(8, 1);
    point = res = 0;
}
void replacing (int i) {
    FOR (j, 0, 7) {
        if (col[j] && l[i-j+8-1] && r[i+j]) {
            col[j] = 0;
            l[i-j+8-1] = 0;
            r[i+j] = 0;
            point += a[i][j];
            if (i == 7) {
                res = max(res, point);
            }
            else replacing(i+1);
            point -= a[i][j];
            col[j] = 1;
            l[i-j+8-1] = 1;
            r[i+j] = 1;
        }
    }
}
void test () {
    init();
    replacing(0);
    cout << res << endl;
    a.clear(), col.clear(), l.clear(), r.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test ();
    return 0;
}