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
ll n, x;
void test () {
    priority_queue <ll, vector<ll>, greater<ll> > q;
    cin >> n;
    while (n--) {
        cin >> x;
        q.push(x);
    }
    ll sum = 0;
    while (q.size() > 1) {
        x = q.top();
        q.pop();
        x += q.top();
        x %= mod;
        q.pop();
        q.push(x);
        sum += x;
        sum %= mod;
    }
    cout << sum << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}