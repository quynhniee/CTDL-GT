#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <set>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
set<vector<int> > ans;
vector<int> a, temp;
int n, s;
void init () {
    cin >> n;
    s = 0;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
    sort(a.begin(), a.end(), greater<int>());
}
void backtracking (int i) {
    FOR (j, i, n-1) {
        temp.push_back(a[j]);
        s += a[j];
        if (s % 2 == 1) ans.insert(temp);
        if (i < n)  backtracking(j+1);
        s -= a[j];
        temp.pop_back();
    }
}
void test () {
    init();
    backtracking(0);
    for (auto i:ans) {
        for (auto j:i)  cout << j << " ";
        cout << endl;
    }
    ans.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test();
    return 0;
}