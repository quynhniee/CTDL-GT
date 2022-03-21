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
int n, res;
vector<string> s;
vector<int> p;
void input () {
    cin >> n;
    s.assign(n, "");
    p.assign(n, 0);
    FOR (i, 0, n-1) {
        cin >> s[i];
        p[i] = i;
    }
    res = 1e6+5;
}
void count () {
    int cou = 0;
    FOR (k, 1, n-1) {
        int i = 0, j = 0;
        while (i < s[p[k-1]].size() && j < s[p[k]].size()) {
            if (s[p[k-1]][i] == s[p[k]][j])
                ++cou, ++i, ++j;
            else if (s[p[k-1]][i] > s[p[k]][j]) ++j;
            else    ++i;
            if (cou >= res) return;
        }
    }
    res = min(res, cou);
}
void test () {
    input ();
    do  count();
    while (next_permutation(p.begin(), p.end()));
    cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}