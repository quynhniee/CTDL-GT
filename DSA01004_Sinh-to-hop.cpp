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
vector<int> a;
int n, k;
void init () {
    cin >> n >> k;
    a.resize(k + 1, 0);
    for (int i = 1; i <= k; i++)    a[i] = i;
}
void output () {
    for (int i = 1; i <= k; i++)    cout << a[i];
    cout << " ";
}
void combination (int pos) {
    for (int i = a[pos - 1] + 1; i <= n - k + pos; i++) {
        a[pos] = i; 
        if (pos == k)   output();
        else    combination(pos + 1);
    }
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        init();
        combination(1);
        a.clear();
        cout << endl;
    }
    return 0;
}