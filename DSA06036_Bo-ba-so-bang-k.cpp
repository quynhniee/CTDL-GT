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
ll n, k;
vector<ll> a;
void input () {
    cin >> n >> k;
    a.resize(n);
    for (auto &i : a)   cin >> i;
    stable_sort(a.begin(), a.end());
}
void test () {
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            if (binary_search(a.begin() + j + 1, a.end(), k - a[i] - a[j])) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}
void test2 () {
    int x1 = n - 1, x2 = x1 - 1, x3 = 0;
    while (x2 != 0 && k != a[x1] + a[x2] + a[x3]) {
        if (k > a[x1] + a[x2] + a[x3])  x3++;
        else if (k < a[x1] + a[x2] + a[x3]) x2--;
        if (x2 == x3) {
            x1--;
            x2 = x1 - 1;
            x3 = 0;
        }
    }
    (x2 != 0) ? cout << "YES\n" : cout << "NO\n";
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        input();
        test2();
        a.clear();
    }
    return 0;
}