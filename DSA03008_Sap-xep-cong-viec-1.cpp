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
vector<pair<int, int> > a;

void test () {
    cin >> n;
    int cou = 1;
    a.assign(n, {0, 0});
    for (auto &i:a) cin >> i.first;
    for (auto &i:a) cin >> i.second;
    sort(a.begin(), a.end());
    int rem = a[0].second;
    FOR (i, 1, n-1) {
        if (a[i].first >= rem) {
            ++cou; 
            rem = a[i].second;
        }
        else    rem = min (rem, a[i].second);
    }
    cout << cou << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}