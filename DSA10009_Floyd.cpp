#include <bits/stdc++.h>
#define tester()	int t; cin >> t; while (t--)
using namespace std;
int n, m, q;
vector <vector<int> > a;
void init () {
	cin >> n >> m;
	a.assign(n+5, vector<int> (n+5, 1e5));
	for (int i = 1; i <= n; i++)	a[i][i] = 0;
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		a[x][y] = a[y][x] = z;
	}	
}
void floyd () {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j and i != k and a[i][j] > a[i][k] + a[k][j])
					a[i][j] = a[i][k] + a[k][j];
}
void output () {
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << a[x][y] << endl;
	}
}
void test_case () {
	init ();
	floyd();
	output();
}
int main() {
	test_case();
	return 0;
}
