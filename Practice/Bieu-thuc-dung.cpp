#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string s;
void test_case() {
	scanf ("\n");
	getline (cin, s);
	stack<char> st;
	int res = 0, cou = 0;
	for (char i:s) {
		if (i == ' ')	continue;
		if (i == '(')  {
			st.push(i);
			cou++;
		}
		else if (i == ')' && !st.empty() && st.top() == '(') {
			cou--;
			st.pop();
		}
		res = max (res, cou);
	}
	st.empty() ? cout << res << endl : cout << "-1\n";
}

int main () {
	int t;
	cin >> t;
	while (t--) test_case();
    return 0;
}

