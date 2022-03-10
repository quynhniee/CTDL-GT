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
matrix operator* (matrix a, matrix b) {
    matrix c(n, vector<ll> (n, 0));
    FOR (i, 0, n-1)
        FOR (j, 0, n-1)
            FOR (K, 0, n-1) {
                c[i][j] += a[i][K] * b[K][j];
                c[i][j] %= mod;
            }
    return c;
}

matrix a;
void input () {
    cin >> n >> k;
    a.assign(n, vector<ll>(n, 0));
    for (auto &i:a) 
        for (auto &j:i)  cin >> j;
}
matrix matrix_exponention (int k) {
    if (k == 1) return a;
    matrix x = matrix_exponention(k/2);
    matrix temp = x * x;
    if (k % 2 == 0) return temp;
    else    return a * temp;
}
void output (matrix x) {
    for (auto i:x) {
        for (auto j:i)  cout << j << " ";
        cout << endl;
    }
}
void test () {
    input();
    matrix res = matrix_exponention(k);
    output(res);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}