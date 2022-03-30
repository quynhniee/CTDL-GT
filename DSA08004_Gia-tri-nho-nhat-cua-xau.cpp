#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string s;
ll k;
void test () {
    vector<ll> a (27, 0);
    cin >> k >> s;
    for (auto i:s)
        a[i-'A']++;
    priority_queue<ll> pq;
    for (auto i:a)
        if (i)  pq.push(i);
    ll tmp;
    while (k--) {
        tmp = pq.top();
        pq.pop();
        pq.push(tmp-1);
    }
    ll res = 0;
    while (!pq.empty()) {
        tmp = pq.top(); pq.pop();
        res += tmp * tmp;
    }
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}