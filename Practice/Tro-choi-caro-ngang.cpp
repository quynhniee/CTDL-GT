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
char c;
bool check (string s) {
    int cou_x = 1, cou_o = 1, max_x = 0, max_o = 0;
    FOR (i, 0, s.size()-1) {
        (s[i-1] == 'X' && s[i] == 'X') ?  ++cou_x : cou_x = 1;
        max_x = max (max_x, cou_x);
        (s[i-1] == 'O' && s[i] == 'O') ?  ++cou_o : cou_o = 1;
        max_o = max (max_o, cou_o);
    }
    return (c == 'X' && max_x >= 5 && max_x > max_o) || (c == 'O' && max_o >= 5 && max_o > max_x);
}
void backtracking (int i, string s) {
    if (i == n && check(s))    cout << s << endl;
    else if ( i < n) {
        backtracking(i+1, s + "O");
        backtracking(i+1, s + "X");
    }
}
void solution () {
    cin >> n >> c;
    backtracking(0, "");
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}