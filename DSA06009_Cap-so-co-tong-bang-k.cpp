#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <map>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n, k, dem;
vector<int> a;
void test () {
    dem = 0;
    cin >> n >> k;
    a.resize(n);
    for (auto &i:a) 
        cin >> i;
    for (int i = 0; i < n-1; i++) 
        for (int j = i + 1; j < n; j++)
            if (a[i] + a[j] == k)
                ++dem;
    cout << dem << endl;
    a.clear();
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