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
vector<int> c, a;
int n, k;
void output () {
    for (auto i:c)  cout << i << " ";
    cout << endl;
}
void backtracking (int i) {
    FOR (j, i, n-1) {
        c.push_back(a[j]);
        if (c.size() == k) output();
        else if (c.size() < k) backtracking(j+1);
        c.pop_back();
    }
}
void test () {
    cin >> n >> k;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
    sort(a.begin(), a.end());
    backtracking(0);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test();
    return 0;
}