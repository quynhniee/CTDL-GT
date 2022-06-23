#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
void test_case () {
	int n; cin >> n;
	vector <int> a(n+1, 0);
	FOR (i, 0, n-1)	 {
		int x; cin >> x;
		a[x] = a[x-1] + 1;
	}
	cout << n - *max_element (a.begin(), a.end()) << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test_case();
    return 0;
}

