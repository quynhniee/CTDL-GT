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
void input () {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void insertionSort () {
	vector <int> b;
	int step = 0;
	for (int i = 0; i < n; i++) {
		cout << "Buoc " << step++ << ":";
		b.push_back(a[i]);
		sort (b.begin(), b.end());
		for (auto j : b)	cout << " " << j;
		cout << endl;
	}
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input ();
    insertionSort();
    return 0;
}

