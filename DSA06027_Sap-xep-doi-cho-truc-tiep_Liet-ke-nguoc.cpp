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
int n;
vector<int> a;
vector<vector<int> > ans;
void input () {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void interchangeSort () {
	for (int i = 0; i < n -1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])	swap (a[i], a[j]);
		}
		ans.push_back(a);
	}
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << "Buoc " << i + 1 << ":";
        for (auto j : ans[i])   cout << " " << j;
        cout << endl;
    }
	a.clear();
    ans.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        input ();
        interchangeSort();
    }
    return 0;
}


