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
    matrix c (n, vector<ll> (n, 0));
    FOR (i, 0, n-1)
        FOR (j, 0, n-1)
            FOR (k, 0, n-1)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    return c; 
}
matrix a;
matrix devide (int k) {
    if (k == 1) return a;
    else {
        matrix temp = devide(k/2);
        if (k %2 == 0)  return temp * temp;
        else return temp * temp * a;
    }
}
void input () {
    cin >> n >> k;
    a.assign(n, vector<ll> (n, 0));
    for (auto &i:a)
        for (auto &j:i)
            cin >> j;
}
void output (matrix x) {
    // tổng phần tử hàng cuối cùng
    ll sum = 0;
    FOR (i, 0, n-1)
        sum = (sum + x[n-1][i]) % mod;
    cout << sum << endl;
}
void test () {
    input();
    output(devide(k));
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}