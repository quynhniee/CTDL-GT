#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;

int n, m;
vector <vector <int> > a, vs;
void init () {
	cin >> n >> m;
	a.assign (n, vector <int> (m, 0));
	vs.assign (n, vector <int> (m, 0));
	for (auto &i:a)
		for (auto &j:i)	cin >> j;
}
struct Data {
	int x, y, w;
	Data (int x, int y, int w) {
		this->x = x;
		this->y = y;
		this->w = w;
	}
};
void test_case () {
	init ();
	queue<Data> q;
	q.push(Data(0, 0, 0));
	while (!q.empty()) {
		Data tmp = q.front(); q.pop();
		int i = tmp.x, j = tmp.y;
		if (i == n-1 and j == m-1) {
			cout << tmp.w << endl;
			return;
		}
		if (i + a[i][j] < n and !vs[i + a[i][j]][j]) {
			vs[i + a[i][j]][j] = 1;
			q.push(Data(i+a[i][j], j, tmp.w + 1));
		}
		if (j + a[i][j] < m and !vs[i][j + a[i][j]]) {
			vs[i][j + a[i][j]] = 1;
			q.push(Data(i, j + a[i][j], tmp.w + 1));
		}
	}
	cout << "-1\n";
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()	test_case();
    return 0;
}

