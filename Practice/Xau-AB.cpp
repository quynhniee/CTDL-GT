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
vector <string> res;
void backtracking (int i, string s) {
    if (i == n) res.push_back(s);
    else {
        backtracking(i+1, s + "A");
        backtracking(i+1, s + "B");
    }
}
void output () {
    if (res.size() > 1) 
        FOR (i, 0, res.size()-2)    cout << res[i] << ",";
    cout << res.back() << endl;
    res.clear();
}
void solution () {
    cin >> n;
    backtracking(0, "");
    output();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    solution();
    return 0;
}