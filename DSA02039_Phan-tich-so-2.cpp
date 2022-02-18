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
#define tester()   int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;

int n, s, cou;
vector<int> ans;
vector<vector<int> > arr;
void output () {
	FOR (j, 0, arr.size()-1) {
		cout << "(";
		if (arr[j].size() > 1)
			FOR (i, 0, arr[j].size()-2)	
				cout << arr[j][i] << " ";
		cout << arr[j].back() << ") ";
	}	
}
void backtracking (int val) {
	FORD (i, val, 1) {
		ans.push_back(i);
		s += i;
		if (s == n)	 {
			arr.push_back(ans);
			++cou;
		}
		else if (s < n)
			backtracking (i);
		s -= i;
		ans.pop_back();
	}
}
void test () {
	cou = 0;
	s = 0;
	cin >> n;
	backtracking (n);
	cout << cou << endl;
	output ();
	ans.clear();
	arr.clear();
	cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
    	test ();
    return 0;
}

