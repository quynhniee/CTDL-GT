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
int n;
vector<ll> step {0, 1, 2, 4};
void dynamic () {
    FOR (i, 4, 50)
        step.push_back(step[i-1] + step[i-2] + step[i-3]);
}
void test () {
    cin >> n;
    cout << step[n] << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    dynamic();
    tester()    test();
    return 0;
}