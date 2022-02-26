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
void test () {
    cin >> n;
    a.assign(n, 0);
    for (auto &i:a) cin >> i;
    sort(a.begin(), a.end());
    do {
        for (auto i:a)  cout << i << " ";
        cout << endl;
    }
    while (next_permutation(a.begin(), a.end()));
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test ();
    return 0;
}