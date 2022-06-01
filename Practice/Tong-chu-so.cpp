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
string n;
int s;
void test_case () {
	string res = "";
	cin >> n >> s;
	int s1 = 0, rem = 0;
	FORD (i, n.size()-1, 0) {
		int x = n[i] - '0' + rem; rem = 0;
		if (x > 9)	{
			res = 	to_string (x % 10) + res;
			rem = 1;
		}  
		else res = to_string (x ) + res;
		s1 += x;
		if (s1 > s) {
			res.assign(n.size()-i, '0');
			s1 -= x;
			rem = 1;
		}
	}
	if (rem)	res = "1" + res;
	cout << stoll(res) - stoll(n) << endl;
}
int main () {
   
    int t;
    cin >> t;
    while (t--)	test_case();
    return 0;
}

