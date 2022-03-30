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
vector<int> a;
int n;
void init () {
    cin >> n;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
}
// tổng dãy con tăng dần lớn nhất (có thể không liên tiếp)
vector<int> IncreasingArray () {
    vector<int> incr = a;
    FOR (i, 1, n-1)
        FOR (j, 0, i-1)
            if (a[i] > a[j] && a[i] + incr[j] > incr[i])
                incr[i] = a[i] + incr[j];
    return incr;
}
// tổng dãy con giảm dần lớn nhất
vector<int> DecreasingArray () {
    vector<int> decr = a;
    FORD (i, n-2, 0)
        FORD (j, n-1, i+1)
            if (a[i] > a[j] && a[i] + decr[j] > decr[i])
                decr[i] = a[i] + decr[j];
    return decr;
}
void solution () {
    int res = 0;
    vector<int> incr = IncreasingArray(), decr = DecreasingArray();
    FOR (i, 0, n-1)
        res = max (res, incr[i] + decr[i] - a[i]);
    cout << res << endl;
}

void test () {
    init();
    solution();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}