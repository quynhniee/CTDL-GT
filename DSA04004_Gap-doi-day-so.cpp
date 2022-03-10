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
ll k, n;
bool stop;
vector<ll> pos;
void test () {
    stop = false;
    cin >> n >> k;
    pos.assign(n, 1);
    FOR (i, 1, n-1) 
        pos[i] = (pos[i-1] << 1);
    FORD (i, n-1, 0)
        if (k == pos[i]) {
            cout << i+1 << endl;
            return;
        }
        else if (k > pos[i])
            k -= pos[i];
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()    test();
    return 0;
}