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
    FOR (i, 0, n-1) cin >> a[i];
}
/* Một dãy con liên tiếp được gọi là dãy tam giác nếu như 
dãy đó tăng dần rồi lại giảm dần 
=> 	dãy tăng dần chạy từ 0->n-1;
	dãy giam dần chạy từ n-1->0;
=> tại mỗi đỉnh i biết được dãy tăng bậc mấy, giảm bậc mấy
*/
void triangleArr () {
    vector<int> incr(n, 0), decr(n, 0);
    incr[0] = decr [n-1] = 1;
	FOR (i, 1, n-1)
		if (a[i] > a[i-1])	incr[i] = incr[i-1] + 1;
		else	incr[i] = 1;
	FORD (i, n-2, 0)
		if (a[i] > a[i+1])	decr[i] = decr[i+1] + 1;
		else	decr[i] = 1;

	int size = 0;
    FOR (i, 0, n-1) {
    	size = max (size, incr[i] + decr[i] - 1);
	}
	cout << size << endl;
}
void test () {
    input();
    triangleArr();
    a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   int t;
   cin >> t;
   while (t--)
    	test();
    return 0;
}
