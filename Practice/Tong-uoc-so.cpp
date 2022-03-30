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
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int a, b; 
vector<ll> dp (1e7);
void solution () {
    for (int i = 1; i <= b; i++)
        for (int j = i*2; j <= b; j += i)
            dp[j] += i;
}
void test () {
    cin >> a >> b;
    solution();
    ll cou = 0;
    FOR (i, a, b)
        if (dp[i] > i)  ++cou; 
    cout << cou << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}