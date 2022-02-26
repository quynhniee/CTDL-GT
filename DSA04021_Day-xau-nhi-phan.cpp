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
vector<ll> fibo;
void fiboArray () {
    fibo.assign({0, 1, 1});
    FOR (i, 3, 92) 
        fibo.push_back(fibo[i-1] + fibo[i-2]);
}
ll n, k;
void devide (ll pos, ll i) {
    if (i == 1) cout << "0\n";
    else if (i == 2)  cout << "1\n";
    else {
        if (pos <= fibo[i-2])  devide(pos, i-2);
        else    devide(pos - fibo[i-2], i-1);
    }
}
void test () {
    cin >> n >> k;
    devide(k, n);
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    fiboArray();
    tester()
        test();
    return 0;
}