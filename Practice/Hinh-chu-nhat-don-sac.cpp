#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <stack>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
ll solve(vector<int> a) {
	int n = a.size();
	vector<int> l(n, -1), r(n, n);
	stack <int> st;
	st.push(-1);
	for (int i = 0; i < n; ++i) {
		while(st.top() != -1 && a[st.top()] > a[i]) {
			r[st.top()] = i;
			st.pop();
		}
		if(i > 0 && a[i] == a[st.top()])
			l[i] = l[st.top()];
		else l[i] = st.top();
		st.push(i);
	}
	ll res = 0;
	for (int i = 0; i < n; ++i)
		res = max(res, (ll)a[i] * (r[i] - l[i] - 1));
	return res;
}

void solution() {
	int k, n;
	cin >> k >> n;
	vector<int> a(n), b;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b.push_back(k-a[i]);
	}
	ll ans = solve(a);
	ans = max(ans, solve(b));
	cout << ans << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}