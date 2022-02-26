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
ll n, k, cou;
vector<int> a;
void test () {
    cou = 1;
    cin >> n >> k;
    a.assign(n, 0);
    FOR (i, 0, n-1) 
        cin >> a[i];
    while (!a.front())  a.erase(a.begin());
    while (!a.back())   a.erase(a.end()-1);
    int zeroes = 0;
    FOR (i, 0, a.size()-1) {
        if (a[i] == 0) ++zeroes;
        else if (zeroes) {
            cou *= (zeroes + 1);
            zeroes = 0;
        }   
    }
    cout << cou << endl;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
    return 0;
}