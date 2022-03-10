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
vector<ll> a, ans;
void input () {
    cin >> n;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
}
void output (vector<ll> &q) {
    for (auto i:q)  cout << i << " ";
    cout << endl;
    q.clear();
}
void solve () {
    vector<ll> Max(n), Min(n);
    Min[n-1] = a[n-1], Max[0] = a[0];
    FOR (i, 1, n-1)  // max của dãy [0, i]
        Max[i] = max(a[i], Max[i-1]);
    FORD (i, n-2, 0) // min của dãy [i+1, n-1] ** không lấy vị trí tại i
        Min[i] = min(a[i+1], Min[i+1]);
    FOR (i, 0, n-2)
        if (Max[i] <= Min[i])
            ans.push_back(i+1);
    cout << ans.size() << endl;
    output(ans);
}
void test () {
    input ();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}