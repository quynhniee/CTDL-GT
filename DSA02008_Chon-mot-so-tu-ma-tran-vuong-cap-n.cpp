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
int n, k, s, cou;
vector<vector<int> > a, ans;
vector<int> col, step;
void input () {
    cin >> n >> k;
    a.assign(n+1, vector<int>(n+1));
    col.assign(n+1, 1);
    s = cou = 0;
    FOR (i, 1, n)
        FOR (j, 1, n)
            cin >> a[i][j];
}
void backtracking (int i) {
    FOR (j, 1, n) {
        if (col[j]) {
            col[j] = 0;
            step.push_back(j);
            s += a[i][j];
            if (i == n && s == k) {
                    ++cou;
                    ans.push_back(step);
            }
            else if (i < n && s < k) backtracking(i+1);
            s -= a[i][j];
            step.pop_back();
            col[j] = 1;
        }
    }
}
void ouput () {
    cout << cou << endl;
    for (auto i:ans) {
        for (auto j:i)  cout << j << " ";
        cout << endl;
    }
}
void test () {
    input();
    backtracking(1);
    ouput();
    ans.clear();
    step.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}