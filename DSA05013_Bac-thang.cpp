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
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, k;
vector<ll> step;
/* 
- Mỗi lần đi được tối đa k bước (tương tự Đếm dãy)
=> i thuộc [1, k]: có i << (i-1) cách  (k lớn, không dùng pow/dịch bit)
hoặc bằng tổng tất cả phần tử trước nó với [0] = 1;
*/
void test () {
    cin >> n >> k;
    step.assign(1, 1);
    int m = min(n, k);
    ll s = 0;
    FOR (i, 1, m) {
        s += step[i-1];
        step.push_back(s % mod);
    }
    FOR (i, m+1, n) {
        s = s - step[i-1-m] + step[i-1];
        step.push_back(s % mod);
    }
    cout << step[n] << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}