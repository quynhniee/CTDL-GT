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
vector<int> a, ans;
int n, s, x;
bool mark;
void init () {
    mark = false;
    cin >> n >> x;
    int index;
    set<int> temp;
    FOR (i, 0, n-1) {
        cin >> index;
        temp.insert(index);
    }
    for (auto i:temp)   a.push_back(i);
}
void output () {
    cout << "[";
    if (ans.size() > 1) 
        FOR (i, 0, ans.size()-2)    cout << ans[i] << " ";
    cout << ans.back() << "]";
}
void backtracking (int i) {
    FOR (j, i, n-1) {
        s += a[j];
        ans.push_back(a[j]);
        if (s == x) {
            output();
            mark = true;
        }
        else if (s < x && i < n) backtracking (j);
        s -= a[j];
        ans.pop_back();
    }
}
void test () {
    s = 0;
    init();
    backtracking(0);
    if (!mark)  cout << "-1";
    cout << endl;
    a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test();
    return 0;
}