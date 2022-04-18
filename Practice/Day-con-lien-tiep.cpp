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
vector<ll> a;
int n;
void test() {
	cin >> n;
    a.assign(n, 0);
	for (ll &i : a) cin >> i;
	int res = 0, cou = 0;
	ll max_val = *max_element(a.begin(), a.end());
	FOR (i, 0, n-1){ 
		a[i-1] == max_val && a[i] == max_val ? ++cou : cou = 1;
		res = max (res, cou);
	}
	cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}