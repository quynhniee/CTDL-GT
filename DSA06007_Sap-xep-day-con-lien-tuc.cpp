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
vector<int> a, b;
int n;
void test () {
    cin >> n;
    a.resize(n);
    for (auto &i:a) {
        cin >> i;
        b.push_back(i);
    }
    sort(b.begin(), b.end());
    int r = n-1, l = 0;
    while (a[l] == b[l])    ++l;
    while (a[r] == b[r])    --r;
    cout << l+1 << " " << r+1 << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        test();
        a.clear();
        b.clear();
    }
    return 0;
}