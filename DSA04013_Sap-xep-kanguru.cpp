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
vector<int> a;
void input () {
    cin >> n;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
}

void solve () {
    sort(a.begin(), a.end());
    int cou = n, r = n - 1, l = n/2 - 1;
    while (l >= 0 && r >= n/2) {
        if (a[r] >= a[l] * 2) 
            --cou, --r, --l;
        else    --l;
    }
    cout << cou << endl;
}
void test () {
    input();
    solve();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}