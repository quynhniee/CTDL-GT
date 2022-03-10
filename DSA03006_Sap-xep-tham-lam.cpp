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
vector<int> a, b;
void test () {
    cin >> n;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
    b.assign(a.begin(), a.end());
    sort(b.begin(), b.end());
    int pivot = (n+1)/2;
    FOR (i, 0, pivot) 
        if (a[i] != b[i] && b[i] != a[n-1-i]) {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
}
/*
1 6 3 4 5 7 2
1 2 3 4 5 6 7
a[1] != b[1] && b[1] != a[5]
*/
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}