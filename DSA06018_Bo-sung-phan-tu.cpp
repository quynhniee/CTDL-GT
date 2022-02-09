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

int n;
set<int> a;
vector <int> vs;
void test () {
    cin >> n;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.insert(x);
    }
    int l = *a.begin();
    int r = *a.rbegin();

    cout << r - l + 1 - a.size() << endl;
    a.clear();
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) 
        test();
    return 0;
}