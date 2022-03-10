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
int n, m, k;
vector<int> a, b;
void input () {
    cin >> n >> m >> k;
    a.assign(n, 0);
    b.assign(m, 0);
    for (auto &i:a) cin >> i;
    for (auto &i:b) cin >> i;
}
void merge () {
    vector<int> res;
    int la = 0, lb = 0, i = 0;
    while (la < n && lb < m) {
        if (a[la] >= b[lb])  res.push_back(b[lb++]);
        else    res.push_back(a[la++]);
    }
    while (la < a.size())   res.push_back(a[la++]);
    while (lb < b.size())   res.push_back(b[lb++]);
    cout << res[k-1] << endl;
}
void test () {
    input();
    merge();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}