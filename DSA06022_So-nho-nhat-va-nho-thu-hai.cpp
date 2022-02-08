#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <set>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, x;
void test () {
    cin >> n;
    set<int> ans;
    while (n--) {
        cin >> x;
        ans.insert(x);
    }
    if (ans.size() < 2) cout << "-1\n";
    else {
        auto it = ans.begin();
        cout << *it << " ";
        ++it;
        cout << *it << endl;
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        test();
    }
    return 0;
}