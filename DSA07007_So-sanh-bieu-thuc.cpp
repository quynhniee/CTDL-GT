#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
string solution (string &s) {
	stack<int> st;
	FOR (i, 0, s.size()-1) {
		if (s[i] == '(')	st.push(i);
		else if (s[i] == ')') {
			if (!st.empty() and s[st.top() - 1] == '-') {
				FOR (j, st.top(), i-1) 
					if (s[j] == '-')	s[j] = '+';
					else if (s[j] == '+')	s[j] = '-';
			}
			st.pop();
		}
	}
	string res = "";
	for (auto i:s)
		if (i != '(' and i != ')')
			res += i;
	return res;
}
void test_case () {
	string s1, s2;
	cin >> s1 >> s2;
	cout << (solution(s1) == solution(s2) ? "YES\n" : "NO\n");
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()	test_case();
    return 0;
}

