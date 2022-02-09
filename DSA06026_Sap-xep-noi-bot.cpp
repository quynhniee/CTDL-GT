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
void bubbleSort () {
	int step = 0;
	bool check;
	for (int i = 0; i < n - 1; i++) {
		check = false;
		for (int j = 0; j < n - i - 1; j++) 
			if (a[j] > a[j + 1]) {
				swap (a[j + 1], a[j]);
				check = true;
			}
		if (check) {
			cout << "Buoc " << ++step << ":";
			for (int k = 0; k < n; k++)	cout << " " << a[k];
			cout << endl;
		}
	}
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    input ();
    bubbleSort ();
    return 0;
}

