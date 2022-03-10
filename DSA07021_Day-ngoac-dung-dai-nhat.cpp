#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <stack>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string s;
void test () {
    stack<int> pos;
    cin >> s;
    int res = 0;
    pos.push(-1);
    FOR (i, 0, s.size()-1) {
        if (!pos.empty() && s[i] == ')' && s[pos.top()] == '(') {
            pos.pop();
            res = max (res, i-pos.top());
        }
        else
            pos.push(i);
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