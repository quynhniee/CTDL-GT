#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <queue>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, x;
priority_queue<int, vector<int>, greater<int> > q;
void test () {
    cin >> n;
    while (n--) {
        cin >> x;
        q.push(x);
    }
    ll s = 0;
    while (true) {
        int val = q.top();
        q.pop();
        val += q.top();
        q.pop();
        s += val;
        if (q.empty())  break;
        q.push(val);
    }
    cout << s << endl;
}
/*
2 4 6 7 9    // 6
  6 6 7 9    // +6+6
      7 9 12 // +7+9
       12 16 // +12+16
*/
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}