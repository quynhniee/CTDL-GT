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
string s;
ll pos, n;
char Try (ll pos, ll n) {
	if (pos <= s.size())	return s[pos-1];
	else if (pos == n/2 + 1)	return Try (n/2, n/2);
	else if (pos <= n/2)	return Try (pos, n/2);
	else	return Try (pos - n/2 -1, n/2);
}
void test_case () {
	cin >> s >> pos;
	n = s.size();
	while (n < pos)	n *= 2;
	cout << Try (pos, n) << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
    test_case();
    return 0;
}

