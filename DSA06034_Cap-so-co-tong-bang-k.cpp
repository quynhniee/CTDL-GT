#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <map>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, k;
void test () {
	map<ll, ll> a;
	cin >> n >> k;
	ll x, cou = 0;
	while (n--) {
		cin >> x;
		a[x]++;
	}
	for (auto i : a) {
		if (i.first * 2 == k)
			cou += i.second * (i.second - 1);
		else 	cou += i.second * a[k - i.first];
	}
	cout << cou / 2 << endl;
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

