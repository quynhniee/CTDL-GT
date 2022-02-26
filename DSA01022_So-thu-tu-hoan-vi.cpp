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
vector<int> a;
vector<int> perm;
void test () {
    cin >> n;
    a.assign(n, 0);
    FOR (i, 0, n-1) {
        cin >> a[i];
        perm.push_back(i+1);
    }
    int cou = 0;
    do {
        ++cou;
        if (perm == a) {
            break;
        }
    }
    while (next_permutation(perm.begin(), perm.end()));
    cout << cou << endl;
    perm.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test();
    return 0;
}