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
void solve () {
    cin >> n;
    vector<int> odd, even;
    vector<int> a(n);
    for (auto &i : a)   cin >> i;
    for (int i = 0; i < n; i += 2)  odd.push_back(a[i]);
    for (int i = 1; i < n; i += 2)  even.push_back(a[i]);
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end(), greater<int>());
    for (int i = 0; i < n/2; i++)   
        cout << odd[i] << " " << even[i] << " ";
    if (n%2 == 1)   cout << odd[n/2];
    cout << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}