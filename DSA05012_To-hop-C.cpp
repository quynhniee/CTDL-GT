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
vector <vector <ll> > C (1005, vector<ll> (1005, 1));
int n, k;
void combination () {
    for (int i = 1; i <= 1000; i++) 
        for (int j = 1; j < i; j++) 
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    combination();
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << C[n][k] << endl;
    }
    return 0;
}