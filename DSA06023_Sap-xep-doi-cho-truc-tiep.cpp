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
void interchangeSort () {
	int step = 0;
	for (int i = 0; i < n -1; i++) {
		cout << "Buoc " << ++step << ":";
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])	swap (a[i], a[j]);
		}
		for (int j = 0; j < n; j++)	
			cout << " " << a[j];
		cout << endl;
	}
	a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input ();
    interchangeSort();
    return 0;
}


