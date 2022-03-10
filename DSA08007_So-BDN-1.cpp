#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <utility>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
ll n;
void test () {
    cin >> n;
    queue<ll> q;
    q.push(1);
    ll temp = q.front(), cou = 0;
    while (temp <= n) {
        ++cou; 
        q.push(temp * 10);
        q.push(temp * 10 + 1);
        q.pop();
        temp = q.front();
    }
    cout << cou << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}