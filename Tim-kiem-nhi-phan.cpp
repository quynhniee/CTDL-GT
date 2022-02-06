
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
void input () {
    cin >> n >> k;
    a.resize(n);
    for (auto &i:a) cin >> i;
}
int binarySearch (int val, int l, int r) {
    if (l <= r) {
        int mid = (l+r) / 2;
        if (val == a[mid])  return mid+1;
        else if (val < a[mid])  binarySearch(val, l, mid-1);
        else    binarySearch(val, mid+1, r);
    }
    return -1;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        input();
        cout << binarySearch(k, 0, n-1) << endl;
        a.clear();
    }
    return 0;
}