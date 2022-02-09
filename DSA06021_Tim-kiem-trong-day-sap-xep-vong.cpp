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
int n, x, pivot;
vector<int> a;
int binarySearch (int l, int r) {
    if (l <= r) {
        int mid = (l + r)/2;
        if (a[mid] == x)  
            return mid + 1;
        else if (a[mid] < x)  
            return binarySearch(mid + 1, r);
        else    
            return binarySearch(l, mid - 1);
    }
    return -1;
}

void test () {
    pivot = n;
    cin >> n >> x;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i != 0 && a[i] < a[i-1])    pivot = i;
    }
    int pos = binarySearch(0, pivot - 1);
    if (pos != -1)  
        cout << pos << endl;
    
    else 
        cout << binarySearch(pivot, n - 1) << endl;
    a.clear();
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