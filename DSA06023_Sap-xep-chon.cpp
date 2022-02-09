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
void init () {
	cin >> n;
	a.resize(n);
	for (auto &i : a)	cin >> i;
}
void selectionSort () {
	int step = 1;
	for (int i = 0; i < n - 1; i++) {
		int pos = i;
		for (int j = i + 1; j < n; j++) 
			if (a[j] < a[pos])
				pos = j;
		swap(a[i], a[pos]);
		cout << "Buoc " << step++ << ":";
		for (auto k : a)	cout << " " << k;
		cout << endl;
	}
	a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    init ();
    selectionSort ();
    return 0;
}

