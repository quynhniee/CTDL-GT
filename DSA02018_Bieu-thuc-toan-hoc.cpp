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
vector <int> a;
int n;
bool isValid;
void init () {
	n = 5;
	a.assign(n, 0);
	for (auto &i:a)	cin >> i;
	isValid = false;
}
void Try (int i, int s) {
	if (isValid)	return;
	if (i == n and s == 23) isValid = true;
	else if (i < n) {
		Try (i+1, s + a[i]);
		Try (i+1, s - a[i]);
		Try (i+1, s * a[i]);
	}
}
void test_case () {
	init ();
	sort (a.begin(), a.end());
	do {
		Try (1, a[0]);	
		if (isValid)	break;	
	}
	while (next_permutation (a.begin(), a.end()));
	cout << (isValid ? "YES\n" : "NO\n");
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
    test_case();
    return 0;
}


