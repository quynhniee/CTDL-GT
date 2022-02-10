#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <map>
#include <set>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, x;
void test () {
    map<ll, ll> ans;
    cin >> n;
    set<ll> a;
    for (int i = 0; i < n; i++)   {
        cin >> x;
        a.insert(x);
        ans[x]++;
    }
    int max = 0, val;
    for (auto i : a) 
        if (ans[i] > max && ans[i] > n/2) {
            max = ans[i];
            val = i;
        }
    (max != 0)? cout << val << endl :  cout << "NO\n";
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