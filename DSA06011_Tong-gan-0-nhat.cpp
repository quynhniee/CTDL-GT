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
int n;
vector<int> a;
void test () {
    int s, s_abs = 1e6;
    cin >> n;
    a.resize(n);
    for (auto &i : a)   cin >> i;
    for (int i = 0; i < n-1; i++) 
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            if (abs(sum) < s_abs)   {
                s_abs = abs(sum);
                s = sum;
            }
        }
    cout << s << endl;
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