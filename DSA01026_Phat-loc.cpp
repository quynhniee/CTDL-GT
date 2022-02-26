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
bool check (string s) {
    FOR (i, 3, s.size()-1) {
        // if (s[i] == '8' && s[i-1] == '8')    return false;
        if (s[i-3] == '6' && s[i-2] == '6' && s[i-1] == '6' && s[i] == '6')  return false;
    }
    if (s.back() != '6')    return false;
    return true;
}
void backtracking (string s) {
    if (s.size() == n && check(s)) cout << s << endl;
    else if (s.size() < n) {
        backtracking(s + "6");
        if (s.back() != '8')    backtracking(s + "8");
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    backtracking("8");
    return 0;
}