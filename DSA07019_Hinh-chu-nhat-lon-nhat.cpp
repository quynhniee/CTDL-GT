#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
vector <ll> a;
void init () {
	cin >> n;
	a.assign(n, 0);
	for (auto &i:a)	cin >> i;
}
void output (vector<int> a) {
	for (auto i:a)	cout << i << " ";
	cout << endl;
}
void solution () {
	vector<int> l(n), r(n);
	// vi tri phan tu ben phai dau tien nho hon
	//=> danh dau phan tu ben phai lon hon bang
	stack<int> st;
	FORD (i, n-1, 0) {
		while (!st.empty() and a[i] <= a[st.top()])
			st.pop();
		r[i] = st.empty() ? n-1 : st.top() - 1; 
		st.push(i);
	}
	while (!st.empty())	st.pop();
	// vi tri phan tu ben trai dau tien nho hon
	//=> danh dau phan tu ben trai lon hon bang
	FOR (i, 0, n-1) {
		while (!st.empty() and a[i] <= a[st.top()]) 
			st.pop();
		l[i] = st.empty() ? 0 : st.top() + 1;
		st.push(i);
	}
	// ket qua
	ll res = 0;
	FOR (i, 0, n-1) 
		res = max (res, (ll) a[i] * (r[i] - l[i] + 1));
	cout << res << endl;
}
void test_case () {
	init ();
	solution();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester () 	test_case();
    return 0;
}

