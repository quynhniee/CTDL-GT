#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string s;
void test_case () {
	cin >> s;
	int res = 0;
	stack<int> st;
	FOR (i, 0, s.size()-1) {
		if (!st.empty() and s[i] == ')' and s[st.top()] == '(') {
			st.pop();
			res += 2;
		}
		else	st.push(i);
	}
	cout << res << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()	test_case();
    return 0;
}

