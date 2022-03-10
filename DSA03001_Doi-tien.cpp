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
vector<int> value {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
int n = value.size();
int N, cou;
void test () {
    cin >> N;
    cou = 0;
    FOR (i, 0, n-1) {
        if (N >= value[i]) {
            cou += N/value[i];
            N %= value[i];
        }
        if (N == 0) break;
    }
    cout << cou << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}