#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;

void test_case () {
	int n; cin >>n;
	vector<int> a(n), ans(n);
	unordered_map<int, int> m;
	for (auto &i:a)	{
		cin >> i;
		m[i]++;
	}
	stack<int> st;
	FORD (i, n-1, 0) {
		while (!st.empty() and m[a[i]] >= m[st.top()])
			st.pop();
		ans[i] = st.empty() ? -1 : st.top();
		st.push(a[i]);
	}
	for (auto i:ans)	cout << i << " ";
	cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()	test_case();
    return 0;
}

