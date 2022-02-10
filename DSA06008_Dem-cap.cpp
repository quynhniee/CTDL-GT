#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
vector<int> x, y, mark;
int n, m;
ll cou;
void input () {
	cin >> n >> m;
	x.resize(n);
	y.resize(m);
	mark.resize(1005, 0);
	for (int i = 0; i < n; i++)	cin >> x[i];
	for (int i = 0; i < m; i++)	{
		cin >> y[i];
		mark[y[i]]++;
	}
	cou = 0;
}
void pairs (int index) {
	if (index == 0)	return;
	else if (index == 1) {
		cou += mark[0];
		return;
	}
	int k = upper_bound(y.begin(), y.end(), index) - y.begin();
	cou += (m - k) + mark[0] + mark[1];
	if (index == 2)
		cou -= (mark[4] + mark[3]);
	else if (index == 3) 
		cou += mark[2];

}
void test () {
	input ();
	sort (y.begin(), y.end());
	for (int i = 0; i < n; i++) {
		pairs (x[i]);
	}
	cout << cou << endl;
	x.clear();
	y.clear();
	mark.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    	test ();
    return 0;
}

