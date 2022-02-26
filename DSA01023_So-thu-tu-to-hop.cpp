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
int n, k, cou;
vector<int> a;
vector<int> comb;
void next_combination (int i) {
    FOR (j, comb[i-1] + 1, n - k + i) {
        comb[i] = j;
        if (i==k) {
            ++cou;
            if (comb == a)  {
                cout << cou << endl;
                return;
            }
        } 
        else next_combination(i+1);
    }
}
void test () {
    cou = 0;
    cin >> n >> k;
    a.assign(k+1, 0);
    comb.assign(k+1, 0);
    FOR (i, 1, k)   {
        cin >> a[i];
        comb[i] = i;
    }
    next_combination(1);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        test();
    return 0;
}