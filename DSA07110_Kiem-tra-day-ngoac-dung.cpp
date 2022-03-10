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
    cin >> s;
    stack<char> a;
    FOR (i, 0, s.size()-1) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            a.push(s[i]);
        else if (!a.empty() && ((s[i] == ')' && a.top() == '(') || (s[i] == ']' && a.top() == '[') || (s[i] == '}' && a.top() == '{')))
            a.pop();
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}