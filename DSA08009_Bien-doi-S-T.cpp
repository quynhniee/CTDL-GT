#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <unordered_map>
#include <queue>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int s, t;
void test_case () {
	cin >> s >> t;
	queue<pair<int, int> > q; q.push({s, 0});
	unordered_map<int, int> m;
	while (!q.empty()) {
		pair<int, int> tmp = q.front(); q.pop();
		int i = tmp.first, j = tmp.second;
		if (i == t) {
			cout << j << endl;
			return;
		}
		else if (i * 2 == t or i - 1 == t) {
			cout << j + 1 << endl;
			return;
		}
		if (i * 2 < t * 2 and !m[i*2]) {
			m[i*2]++;
			q.push({i*2, j+1});
		}
		if (i - 1 >= 0 and !m[i-1]) {
			m[i-1]++;
			q.push({i-1, j+1});
		}
	}
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()	test_case();
    return 0;
}

