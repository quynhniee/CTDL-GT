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
int n, k;
vector<int> a;
void init () {
    cin >> n >> k;
    a.resize(k + 1);
    for (int i = 1; i <= k; ++i)   cin >> a[i];
}
void next_combination () {
    int i = k;
    while (a[i] == n - k + i)
        --i;
    if (i > 0)
        a[i]++;
    else 
        for (auto &i : a)   i = 0;
    for (int j = 1; j <= k - i; ++j)
        a[i + j] = a[i] + j;
}
void output () {
    for (int i = 1; i <= k; ++i)    cout << a[i] << " ";
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        init();
        next_combination();
        output();
        a.clear();
    }
    return 0;
}