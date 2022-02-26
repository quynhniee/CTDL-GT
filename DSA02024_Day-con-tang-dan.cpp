#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ostream>
#include <set>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
vector<string> a, bin;
set<vector<string> > ans;
void init () {
    cin >> n;
	a.assign(n, "");
	FOR (i, 0, n-1)	cin >> a[i];
}
void output () {
	for (auto i:ans) {
        for (auto j:i)
            cout << j << " ";
        cout << endl;
    }
}

void backtracking (int i) {
	FOR (j, i+1, n-1) {
		if (stoi(a[j]) > stoi(bin.back())) {
			bin.push_back(a[j]);
			ans.insert(bin);
			if (i == n-1)	return;
			else	backtracking (j);
			bin.pop_back();	
		}
	}
}
void test () {
    init();
    FOR (i, 0, n-1) {
        bin.push_back(a[i]);
        backtracking(i);
        bin.clear();
    }
    output();
    ans.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}
