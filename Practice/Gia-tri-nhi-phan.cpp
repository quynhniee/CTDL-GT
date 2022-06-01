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
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
void test_case () {
	int n, q;
	cin >> n >> q;
	vector <char> s (n+5, '0');
	while (q--) {
		int x, y;
		cin >> x >> y;
		FOR (i, x, y)
			s[i] = s[i] == '0' ? '1' : '0';
	}
	for (int i = 1; i <= n; i++)	cout << s[i] << " ";
	cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test_case();
    return 0;
}

