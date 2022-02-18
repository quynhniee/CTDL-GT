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

int n, s;
vector<int> ans;
void output () {
	cout << "(";
	if (ans.size() > 1)
		FOR (i, 0, ans.size()-2)	
			cout << ans[i] << " ";
	cout << ans.back() << ") ";
}
void backtracking (int val) {
	FORD (i, val, 1) {
		ans.push_back(i);
		s += i;
		if (s == n)	
			output ();
		else if (s < n)
		backtracking (i);
		s -= i;
		ans.pop_back();
	}
}
void test () {
	s = 0;
	cin >> n;
	backtracking (n);
	ans.clear();
	cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
    	test ();
    return 0;
}

