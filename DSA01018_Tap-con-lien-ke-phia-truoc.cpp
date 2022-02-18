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
vector<int> a;
int n, k;
void init () {
	cin >> n >> k;
	a.resize(k+1);
	for (int i = 1; i <= k; i++)	cin >> a[i];
}
void prev_combination () {
	int i = k - 1;
	while (i > 0 && a[i + 1] == a[i] + 1)
		i--;
	if (i == 0 && a[1] == 1) 
		FOR (j, n - k + 1, n)	
			cout << j << " ";
	else {
		a[++i]--;
		FORD (j, k, i+1) 
			a[j] = n - k + j;
		FOR (j, 1, k)
			cout << a[j] << " ";
	}
	cout << endl;
	a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		init();
		prev_combination();
	}
    return 0;
}

