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
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<int> a, b;
int n, m;
void test () {
    cin >> n >> m;
    ll x, Min = 1e9, Max = -1e9;
    while (n--) {
        cin >> x;
        Max = max (Max, x);
    }
    while (m--) {
        cin >> x;
        Min = min (Min, x);
    }
    cout << Max * Min << endl;
    a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) 
        test ();
    return 0;
}