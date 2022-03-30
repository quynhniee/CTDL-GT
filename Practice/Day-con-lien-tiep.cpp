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
	ll sum = a[0], temp = a[0], ans = 1, pos = 0;
	for (int i = 1; i < n; ++i) {
		sum += a[i];
		while(pos < i && sum / (i-pos+1) < temp) {
			sum -= a[pos];
			++pos;
		}
		ans = max(ans, i-pos+1);
		temp = max(temp, sum/(i-pos+1));
	}
	cout << ans << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}