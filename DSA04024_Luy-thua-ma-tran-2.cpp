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
#define matrix vector<vector<ll> >

int n, k;
matrix matrix_multiply (matrix a, matrix b) {
    matrix c (n, vector<ll>(n, 0));
    ll s;
    FOR (i, 0, n-1) 
        FOR (j, 0, n-1) 
            FOR (K, 0, n-1) {
                c[i][j] += (a[i][K] * b[K][j]) % mod;
                c[i][j] %= mod;
            }
    return c;       
}


matrix a; 

void input () {
    cin >> n >> k;
    a.assign(n, vector<ll>(n, 0));
    FOR (i, 0, n-1)
        FOR (j, 0, n-1)
            cin >> a[i][j];
}

matrix identity_matrix () {
    matrix x (n, vector<ll> (n, 0));
    FOR (i, 0, n-1)
        x[i][i] = 1;
    return x;
}
matrix exponential (int k) {
    if (k == 0) return identity_matrix();
    matrix x = exponential(k/2);
    if (k%2 == 0)   return matrix_multiply(x, x);
    else     return matrix_multiply(a, matrix_multiply(x, x));
}
/*
matrix matrix_exponential (ll n) {
    if (n==1)   return a;
    else return matrix_multiply(a, matrix_exponential(n-1));
}
*/
void result (matrix x) {
    ll s = 0;
    FOR (i, 0, n-1)
        s = (s + x[i][n-1]) % mod;
    cout << s << endl;
}
void test () {
    input();
    matrix res = exponential(k);
    result(res);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}