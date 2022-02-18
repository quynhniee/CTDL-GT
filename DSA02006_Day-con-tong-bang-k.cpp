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
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, k, s;
vector<int> a, vs;
vector<vector<int> > ans;
void init () {
    cin >> n >> k;
    a.resize(n+1);
    vs.resize(n+1, 0);
    FOR(i, 1, n)    cin >> a[i];
    sort(a.begin(), a.end());
    s = 0;
}
void push () {
    vector<int> b;
    FOR (i, 1, n)
        if (vs[i])  b.push_back(a[i]);
   ans.push_back(b);
}
void in () {
    FOR (i, 1, n)   cout << vs[i] << " ";
    cout << endl;
}
void backtrack (int i) {
    if (i > n) {
        if (s == k)   
            push();
        return;
    }
    if (s > k)  return;
    vs[i] = 0;
    s += a[i] * vs[i];
    backtrack(i + 1);
    s -= a[i] * vs[i];
    
    vs[i] = 1;
    s += a[i] * vs[i];
    backtrack(i + 1);
    s -= a[i] * vs[i];
}
void output () {
    if (ans.empty()) {
        cout << "-1\n";
        return;
    }
    FORD (i, ans.size() - 1, 0) {
        cout << "[";
        FOR (j, 0, ans[i].size() - 2)
            cout << ans[i][j] << " ";
        if (ans[i].size() > 1)  cout << ans[i].back();
        cout << "] ";
    }
}
void test () {
    init();
    backtrack(1);
    output();
    cout << endl;
    a.clear(), vs.clear(), ans.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        test();
    }
    return 0;
}