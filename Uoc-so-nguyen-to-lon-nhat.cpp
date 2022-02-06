
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
void test () {
    ll n;
    cin >> n;
    int i = 1;
    while (i + 1 <= sqrt(n)) {
        i++;
        while (n%i == 0)
            n /= i;
    }
    if (n > i)
        i = n;
    cout << i << endl;
}
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        test();    
    return 0;
}