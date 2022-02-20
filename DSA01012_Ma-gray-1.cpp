#include <iostream>
#include <string>
#include <math.h>
#include <climits>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <bitset>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define FORD(i,a,b) for(int i=a;i>=b;--i)
#define tester()    int t; cin >> t; while (t--)
using namespace std;
typedef long long ll;
typedef double db;
const long long mod = 1e9 + 7;
int n;
// g0=b0⊕b1, g1=b1⊕b2, g2=b1⊕b2 , …. g(n-1)=b(n-1)⊕bn, gn=bn.
void GrayCode () {
    cin >> n;
    FOR (i, 0, (1 << n) - 1) {
        string s = bitset<32> (i ^ (i >> 1)).to_string();
        cout << s.substr(32 - n) << " ";
    }
    cout << endl;
}
/* cách 2:
    bin += gray[0];
    FOR (i, 1, n-1) 
        bin += (((gray[i] - '0') + (bin[i-1] - '0')) % 2 + '0')
    cout << bin;

*/
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    tester()
        GrayCode();
    return 0;
}