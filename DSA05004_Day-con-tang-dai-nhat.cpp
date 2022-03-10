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
vector<int> a, top;
int n;
void init () {
    cin >> n;
    a.resize(n), top.resize(n, 1);
    for (auto &i : a) 
        cin >> i;
}
void solve () {
    for (int i = 1; i < n; i++) 
        for (int j = 0; j < i; j++)
            if (a[i] > a[j]) 
                top[i] = max(top[i], top[j] + 1);
    cout << *max_element(top.begin(), top.end()) << endl;
    
}
int main () {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    solve();
    return 0;
}

