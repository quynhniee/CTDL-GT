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
void test () {
    cin >> n;
    vector<int> a(n);
    ll l = 0, r = 0;
    for (auto &i : a)   {
        cin >> i;
        r += i;
    }
    r -= a[0];
    int i = 1;
    while (i < n) {
        l += a[i-1];
        r -= a[i];
        if (l == r) {
            cout << i + 1 << endl;
            return;
        }
        i++;
    }
    cout << "-1\n";
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