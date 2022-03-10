#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <unordered_set>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, m, k;
vector<ll> a, b, c;
vector<ll> matching (vector<ll> a, vector<ll> b) {
    vector<ll> x;
    int la = 0, lb = 0;
    while (la < a.size() && lb < b.size()) {
        if (a[la] == b[lb]) {
            x.push_back(a[la]);
            ++la, ++lb;
        }
        else if (a[la] > b[lb]) ++lb;
        else    ++la;
    }
    return x;
}
void input () {
    cin >> n >> m >> k;
    a.assign(n, 0);
    b.assign(m, 0);
    c.assign(k, 0);
    for (auto &i:a) cin >> i;
    for (auto &i:b) cin >> i;
    for (auto &i:c) cin >> i;
}
void solve () {
    vector<ll> res = matching(matching(a, b), matching(b, c));
    if (res.empty()) cout << "NO";
    else 
        for (auto i:res)    cout << i << " ";
    cout << endl;
}
void test () {
    input();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}