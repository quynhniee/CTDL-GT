#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
void output (vector<int> a) {
	for (auto i:a) cout << i << " ";
	cout << endl;
}
// vi tri phan tu ben phai dau tien lon hon
vector<int> bigger (vector <int> a) {
	vector <int> b (n, -1);
	stack<int> st;
	FORD (i, n-1, 0) {
		while (!st.empty() and a[i] >= a[st.top()])
			st.pop();
		b[i] = st.empty() ? -1 : st.top();
		st.push(i);
	}
	return b;
}
// gia tri phan tu ben phai dau tien nho hon
vector<int> smaller (vector <int> a) {
	vector <int> b (n, -1);
	stack<int> st; 
	FORD (i, n-1, 0) {
		while (!st.empty() and a[i] <= st.top())
			st.pop();
		b[i] = st.empty() ? -1 : st.top();
		st.push(a[i]);
	}
	return b;
}
void test_case () {
	cin >> n;
	vector <int> a (n, 0);
	for (auto &i:a)	cin >> i;
	vector <int> b = bigger(a), s = smaller(a);
	FOR (i, 0, n-1) 
		cout << (b[i] == -1 ? -1 : s[b[i]] )<< " ";
	cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()	test_case();
    return 0;
}

