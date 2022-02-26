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
char x;
int n;
vector<char> a;
vector<bool> vs;
bool check () {
    FOR (i, 1, n-2) {
        if (a[i] == 'A' || a[i] == 'E')
            if (a[i-1] != 'A' && a[i-1] != 'E' && a[i+1] != 'A' && a[i+1] != 'E')
                return false;
    }
    return true;
}
void backtracking (int pos) {
    FOR (i, 0, n-1) {
        if (vs[i]) {
            a.push_back('A' + i);
            vs[i] = false;
            if (pos == n-1 && check()) {
                for (auto j:a)  cout << j;
                cout << endl;
            }
            else if (pos < n)    backtracking(pos + 1);
            a.pop_back();
            vs[i] = true;
        }
    }
}
void test () {
    cin >> x;
    n = x - 'A' + 1;
    vs.assign(n + 1, true);
    backtracking(0);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}