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
int n, x, s;
vector<int> a, temp;
vector<vector<int> > res;
void input () {
    cin >> n >> x;
    s = 0;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
    sort(a.begin(), a.end());
}
void backtrack (int i) {
    FOR (j, i, n-1) {
        s += a[j];
        temp.push_back(a[j]);
        if (s == x)
            res.push_back(temp);
        else if (s < x && i < n) backtrack(j);
        s -= a[j];
        temp.pop_back();
    }
}
void output () {
    if (res.empty()) {
        cout << "-1\n";
        return;
    }
    cout << res.size() << " ";
    for (auto i:res) {
        cout << "{";
        if (i.size() > 1)
            FOR (j, 0, i.size()-2)  cout << i[j] << " ";
        cout << i.back() << "} ";
    }
    cout << endl;
}
void test () {
    input();
    backtrack(0);
    output();
    res.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}