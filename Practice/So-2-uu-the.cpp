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
int n, m;
vector<string> res;
bool check (string s) {
    if (s[0] == '0' || s.size() < 1)    return false;
    int cou = 0;
    for (auto i:s)
        if (i == '2')   ++cou; 
    return cou > s.size()/2;
}
void backtracking (string s) {
    if (res.size() > 1000)  return;
    if (s.size() == m && check(s))   res.push_back(s);
    else if (s.size() < m)
        FOR (i, 0, 2) {
            backtracking(s + to_string(i));
        }
}
void output () {
    FOR (i, 0, n-1) cout << res[i] << " ";
    cout << endl;
}
void stringArray () {
    FOR (i, 1, 1000) {
        m = i;
        backtracking("");
    }
}
void solution () {
    cin >> n;
    output();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    stringArray();
    tester()    solution();
    return 0;
}