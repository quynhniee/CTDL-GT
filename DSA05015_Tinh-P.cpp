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
int n, k;
vector<ll> P;
vector<vector<ll> > C; 
void Combination () {
    C.assign(1001, vector<ll>(1001, 1));
    FOR (i, 1, 1000)
        FOR (j, 1, i-1)
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
}
void Permutation () {
    P = {1, 1};
    FOR (i, 2, 1000)
        P.push_back(P[i-1] * i % mod);
}

void test () {
    cin >> n >> k;
    if (n < k)  cout << "0\n";
    else if (n == k)    cout << "1\n";
    else    cout << C[n][k] * P[k] % mod << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    Combination();
    Permutation();
    tester()    test();
    return 0;
}