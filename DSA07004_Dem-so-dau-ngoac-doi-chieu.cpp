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
stack<char> a;
string s;
void test () {
    int cou = 0;
    cin >> s;
    for (auto i:s) {
        if (!a.empty() && a.top() == '(' && i == ')')
            a.pop();
        else
            a.push(i);
    }
    int open = 0, close = 0;
    while (!a.empty()) {
        a.top() == ')' ? ++close : ++open;
        a.pop();
    }
    cout << (open + 1) / 2 + (close + 1) /2 << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}